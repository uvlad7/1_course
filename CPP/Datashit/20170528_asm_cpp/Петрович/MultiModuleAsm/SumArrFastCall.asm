      .386
      .model flat
      .data
      .code
       PUBLIC @SumArrFastCall
@SumArrFastCall PROC              ; __fastcall
       push   ebp
       mov    ebp, esp

       mov    ebx, eax
       mov    ecx, edx

       xor    eax, eax
c1:
       add    eax, [ebx]
       add    ebx, 4
       loop   c1

       pop    ebp
       ret    8
@SumArrFastCall  ENDP
       end

