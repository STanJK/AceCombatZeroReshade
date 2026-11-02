// Storage annotations verified against R4 caller/callee instructions; no game execution.
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;

public class ApplyCockpitContracts extends GhidraScript {
    private void annotate(String va, DataType ret) throws Exception {
        Function f = getFunctionAt(toAddr(va));
        if (f == null) throw new IllegalStateException("Missing function " + va);
        DataType u8 = UnsignedCharDataType.dataType;
        Parameter[] args = {
            new ParameterImpl("context_or_unused", UnsignedLongLongDataType.dataType, currentProgram),
            new ParameterImpl("logical_slot", u8, currentProgram),
            new ParameterImpl("action", u8, currentProgram)
        };
        f.setReturnType(ret, SourceType.USER_DEFINED);
        f.replaceParameters(Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true,
                            SourceType.USER_DEFINED, args);
        println("ABI_ANNOTATED " + va + " " + f.getPrototypeString(false, false));
    }
    @Override public void run() throws Exception {
        annotate("0x140187a40", UnsignedCharDataType.dataType); // AL
        annotate("0x140187ec0", FloatDataType.dataType);        // XMM0
    }
}
