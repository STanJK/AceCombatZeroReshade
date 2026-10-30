// Export selected pseudocode plus instruction-level evidence; no target execution.
// Arguments: output directory, UTF-8 file containing one absolute VA per line.
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportSelectedFunctions extends GhidraScript {
    private String va(Address a) { return a.isMemoryAddress() ? "0x"+Long.toHexString(a.getOffset()) : a.toString(); }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs(); Path out = Path.of(args[0]); Files.createDirectories(out);
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException(decompiler.getLastMessage());
        List<Object> manifest = new ArrayList<>();
        try {
            for (String line : Files.readAllLines(Path.of(args[1]), StandardCharsets.UTF_8)) {
                monitor.checkCancelled(); String token = line.strip(); if (token.isEmpty() || token.startsWith("#")) continue;
                Address address = toAddr(token); Function f = getFunctionAt(address);
                if (f == null && getFunctionContaining(address) == null && currentProgram.getMemory().getBlock(address) != null
                        && currentProgram.getMemory().getBlock(address).isExecute()) {
                    // Leaf/tail-call callbacks can be absent from PE unwind metadata.
                    // Only seed executable addresses explicitly supplied by the researcher.
                    disassemble(address); f = createFunction(address, null);
                }
                if (f == null) { println("NO_FUNCTION "+token); continue; }
                String id = Long.toHexString(f.getEntryPoint().getOffset());
                Map<String,Object> row = new LinkedHashMap<>();
                row.put("va",va(f.getEntryPoint())); row.put("rva","0x"+Long.toHexString(f.getEntryPoint().subtract(currentProgram.getImageBase())));
                row.put("name",f.getName(true)); row.put("prototype",f.getPrototypeString(false,false)); row.put("size",f.getBody().getNumAddresses());
                List<String> callers = new ArrayList<>(), callees = new ArrayList<>();
                for (Function c : f.getCallingFunctions(monitor)) callers.add(va(c.getEntryPoint()));
                for (Function c : f.getCalledFunctions(monitor)) callees.add(va(c.getEntryPoint()));
                Collections.sort(callers); Collections.sort(callees); row.put("callers",callers); row.put("callees",callees);
                List<Object> incoming = new ArrayList<>();
                ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
                while (rit.hasNext()) { Reference ref = rit.next(); Function c = getFunctionContaining(ref.getFromAddress());
                    incoming.add(Map.of("from",va(ref.getFromAddress()),"type",ref.getReferenceType().toString(),"function",c == null ? "" : va(c.getEntryPoint()))); }
                row.put("incoming_references",incoming);
                DecompileResults result = decompiler.decompileFunction(f,90,monitor);
                row.put("decompile_completed",result.decompileCompleted()); row.put("decompile_error",result.getErrorMessage());
                if (result.decompileCompleted() && result.getDecompiledFunction()!=null) {
                    String header="/* ACZ SHA256: "+currentProgram.getExecutableSHA256()+"\n * VA "+va(f.getEntryPoint())+"; RVA "+row.get("rva")+"\n * Ghidra-generated research pseudocode, inferred types, not original source. */\n";
                    Files.writeString(out.resolve(id+".c"),header+result.getDecompiledFunction().getC(),StandardCharsets.UTF_8);
                }
                StringBuilder asm = new StringBuilder();
                InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(),true);
                while(it.hasNext()) { Instruction ins=it.next(); asm.append(va(ins.getAddress())).append("  ").append(ins).append('\n'); }
                Files.writeString(out.resolve(id+".asm"),asm.toString(),StandardCharsets.UTF_8);
                Files.writeString(out.resolve(id+".json"),new GsonBuilder().setPrettyPrinting().disableHtmlEscaping().create().toJson(row)+"\n",StandardCharsets.UTF_8);
                manifest.add(row); println("EXPORTED "+id+" size="+row.get("size"));
            }
        } finally { decompiler.dispose(); }
        Files.writeString(out.resolve("manifest.json"),new GsonBuilder().setPrettyPrinting().create().toJson(manifest)+"\n",StandardCharsets.UTF_8);
    }
}
