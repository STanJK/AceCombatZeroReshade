// Find instruction-level candidates for player/actor/view fields; no semantic inference.
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;
import com.google.gson.GsonBuilder;

public class ExportWingmanOperands extends GhidraScript {
    @Override public void run() throws Exception {
        Set<String> watched = Set.of("1b8", "1c0", "42b", "20a0", "20a1", "20a2", "2058", "20c8", "a87e4",
            "67230", "671c0", "671f0", "67210", "33d9d8", "310ec0", "316e78", "316e20");
        Pattern hex = Pattern.compile("0x([0-9a-fA-F]+)");
        List<Object> rows = new ArrayList<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            monitor.checkCancelled(); Instruction ins = it.next();
            List<String> found = new ArrayList<>();
            Matcher m = hex.matcher(ins.toString());
            while (m.find()) {
                String value = m.group(1).toLowerCase();
                if (watched.contains(value) || (value.startsWith("140") && watched.contains(value.substring(3)))) found.add(value);
            }
            if (found.isEmpty()) continue;
            Function f = getFunctionContaining(ins.getAddress());
            Map<String,Object> row = new LinkedHashMap<>();
            row.put("va", "0x"+Long.toHexString(ins.getAddress().getOffset()));
            row.put("function", f == null ? "" : "0x"+Long.toHexString(f.getEntryPoint().getOffset()));
            row.put("instruction", ins.toString()); row.put("operands", found); rows.add(row);
        }
        Path p = Path.of(getScriptArgs()[0]); Files.createDirectories(p.getParent());
        Files.writeString(p, new GsonBuilder().setPrettyPrinting().create().toJson(
            Map.of("sha256",currentProgram.getExecutableSHA256(),"image_base",currentProgram.getImageBase().toString(),
                   "scope","operand candidates only; unrelated object/stack offsets are possible","rows",rows))+"\n",StandardCharsets.UTF_8);
        println("WINGMAN_OPERAND_CANDIDATES "+rows.size());
    }
}
