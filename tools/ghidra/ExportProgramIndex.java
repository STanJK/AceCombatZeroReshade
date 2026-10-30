// Export a reproducible static index. Does not execute the target program.
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.framework.Application;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportProgramIndex extends GhidraScript {
    private final Gson gson = new GsonBuilder().setPrettyPrinting().disableHtmlEscaping().create();
    private String va(Address a) { return a.isMemoryAddress() ? "0x" + Long.toHexString(a.getOffset()) : a.toString(); }
    private String rva(Address a) { return "0x" + Long.toHexString(a.subtract(currentProgram.getImageBase())); }
    private void write(Path out, String name, Object data) throws Exception {
        Files.writeString(out.resolve(name), gson.toJson(data) + "\n", StandardCharsets.UTF_8);
    }
    @Override public void run() throws Exception {
        Path out = Path.of(getScriptArgs()[0]); Files.createDirectories(out);
        Map<String,Object> metadata = new LinkedHashMap<>();
        metadata.put("program", currentProgram.getName()); metadata.put("sha256", currentProgram.getExecutableSHA256());
        metadata.put("image_base", va(currentProgram.getImageBase()));
        metadata.put("language", currentProgram.getLanguageID().toString());
        metadata.put("compiler_spec", currentProgram.getCompilerSpec().getCompilerSpecID().toString());
        metadata.put("ghidra", Application.getApplicationVersion());
        List<Object> blocks = new ArrayList<>();
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            blocks.add(Map.of("name", b.getName(), "start", va(b.getStart()), "size", b.getSize(),
                "read", b.isRead(), "write", b.isWrite(), "execute", b.isExecute()));
        }
        metadata.put("blocks", blocks); write(out, "metadata.json", metadata);
        List<Object> functions = new ArrayList<>(), calls = new ArrayList<>(), dataRefs = new ArrayList<>();
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        while (fit.hasNext()) {
            monitor.checkCancelled(); Function f = fit.next();
            Map<String,Object> row = new LinkedHashMap<>();
            row.put("va", va(f.getEntryPoint())); row.put("rva", rva(f.getEntryPoint()));
            row.put("name", f.getName(true)); row.put("size", f.getBody().getNumAddresses());
            row.put("prototype", f.getPrototypeString(false, false)); row.put("thunk", f.isThunk());
            functions.add(row);
            InstructionIterator instructions = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (instructions.hasNext()) {
                Instruction ins = instructions.next();
                for (Reference ref : ins.getReferencesFrom()) {
                    if (ref.getReferenceType().isCall()) {
                        calls.add(Map.of("caller", va(f.getEntryPoint()), "site", va(ins.getAddress()),
                            "target", va(ref.getToAddress()), "type", ref.getReferenceType().toString()));
                    } else if (ref.getReferenceType().isData() && ref.getToAddress().isMemoryAddress()) {
                        MemoryBlock block = currentProgram.getMemory().getBlock(ref.getToAddress());
                        if (block != null) dataRefs.add(Map.of("function", va(f.getEntryPoint()),
                            "site", va(ins.getAddress()), "target", va(ref.getToAddress()),
                            "type", ref.getReferenceType().toString(), "block", block.getName()));
                    }
                }
            }
        }
        write(out,"functions.json",functions); write(out,"calls.json",calls); write(out,"data-references.json",dataRefs);
        List<Object> strings = new ArrayList<>();
        DataIterator dit = currentProgram.getListing().getDefinedData(true);
        while (dit.hasNext()) {
            Data d = dit.next(); if (!(d.getValue() instanceof String)) continue;
            List<Object> refs = new ArrayList<>();
            ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(d.getAddress());
            while (rit.hasNext()) {
                Reference ref = rit.next(); Function f = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
                refs.add(Map.of("from", va(ref.getFromAddress()), "function", f == null ? "" : va(f.getEntryPoint()), "type", ref.getReferenceType().toString()));
            }
            strings.add(Map.of("va", va(d.getAddress()), "value", d.getValue().toString(), "references", refs));
        }
        write(out,"strings.json",strings);
        List<Object> symbols = new ArrayList<>();
        SymbolIterator sit = currentProgram.getSymbolTable().getAllSymbols(true);
        while (sit.hasNext()) {
            Symbol s = sit.next(); if (s.getSource() == SourceType.DEFAULT) continue;
            symbols.add(Map.of("va", va(s.getAddress()), "name", s.getName(true), "type", s.getSymbolType().toString()));
        }
        write(out,"symbols.json",symbols);
        println("INDEX_OK functions="+functions.size()+" calls="+calls.size()+" data_refs="+dataRefs.size()+" strings="+strings.size()+" symbols="+symbols.size());
    }
}
