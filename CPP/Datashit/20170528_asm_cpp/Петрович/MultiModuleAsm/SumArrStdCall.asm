      .386
      .model flat
      .data
      .code
       PUBLIC SumArrStdCall
SumArrStdCall PROC              ; __stdcall
       push   ebp
       mov    ebp, esp

       mov    ebx, [ebp+08h]
       mov    ecx, [ebp+0Ch]

       xor    eax, eax
c1:
       add    eax, [ebx]
       add    ebx, 4
       loop   c1

       pop    ebp
       ret    08h
SumArrStdCall  ENDP
       end

