// Storage-only ABI annotations cross-checked against call-site assembly.
// Does not assign names/semantics to unresolved fields or execute game code.
// @category ACZResearch
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;

public class ApplyKnownInputContracts extends GhidraScript {
    private void annotate(String va, DataType ret, DataType... args) throws Exception {
        Function f = getFunctionAt(toAddr(va));
        if (f == null) throw new IllegalStateException("Missing function "+va);
        Parameter[] parameters = new Parameter[args.length];
        for (int i=0;i<args.length;i++) parameters[i]=new ParameterImpl("arg"+(i+1),args[i],currentProgram);
        f.setReturnType(ret,SourceType.USER_DEFINED);
        f.replaceParameters(Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.USER_DEFINED,parameters);
        println("ABI_ANNOTATED "+va+" "+f.getPrototypeString(false,false));
    }
    @Override public void run() throws Exception {
        DataType u8=UnsignedCharDataType.dataType, u16=UnsignedShortDataType.dataType;
        DataType u64=UnsignedLongLongDataType.dataType, ptr=new PointerDataType(u8);
        annotate("0x140188550",VoidDataType.dataType,u16,ptr,ptr);
        annotate("0x140187c80",u8,u64,u8,u8);
        annotate("0x1400c6a50",VoidDataType.dataType,ptr,u8,u8,ptr,ptr,ptr,u64,ptr,ptr,ptr);
    }
}
