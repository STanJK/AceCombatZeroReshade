// Export literal operand matches. Matches are candidates, not structure/field identities.
// Arguments: output JSON path; UTF-8 watch file (one hexadecimal literal per line).
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;
import com.google.gson.GsonBuilder;

public class ExportOperandCandidates extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        Set<String> watched = new TreeSet<>();
        for (String line : Files.readAllLines(Path.of(args[1]), StandardCharsets.UTF_8)) {
            String value = line.strip().toLowerCase();
            if (value.isEmpty() || value.startsWith("#")) continue;
            if (value.startsWith("0x")) value=value.substring(2);
            if (!value.matches("[0-9a-f]+")) throw new IllegalArgumentException(value);
            watched.add(value);
        }
        Pattern hex = Pattern.compile("0x([0-9a-fA-F]+)");
        List<Object> rows = new ArrayList<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            monitor.checkCancelled(); Instruction ins = it.next();
            Set<String> found = new TreeSet<>();
            Matcher m = hex.matcher(ins.toString());
            while (m.find()) {
                String value=m.group(1).toLowerCase();
                if (watched.contains(value)) found.add(value);
            }
            if (found.isEmpty()) continue;
            Function f=getFunctionContaining(ins.getAddress());
            Map<String,Object> row=new LinkedHashMap<>();
            row.put("va","0x"+Long.toHexString(ins.getAddress().getOffset()));
            row.put("function",f==null?"":"0x"+Long.toHexString(f.getEntryPoint().getOffset()));
            row.put("instruction",ins.toString());row.put("operands",found);rows.add(row);
        }
        Path out=Path.of(args[0]);Files.createDirectories(out.getParent());
        Files.writeString(out,new GsonBuilder().setPrettyPrinting().create().toJson(
            Map.of("sha256",currentProgram.getExecutableSHA256(),"watched",watched,
                   "scope","literal operand candidates; unrelated objects and stack offsets may match","rows",rows))+"\n",StandardCharsets.UTF_8);
        println("OPERAND_CANDIDATES "+rows.size());
    }
}
