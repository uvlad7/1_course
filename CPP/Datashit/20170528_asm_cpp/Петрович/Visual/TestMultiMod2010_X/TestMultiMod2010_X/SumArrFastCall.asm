      .386
      .model flat
      .data
      .code
       PUBLIC @SumArrFastCall@8
@SumArrFastCall@8 PROC
       push   ebp
       mov    ebp, esp

       mov    ebx, ecx
       mov    ecx, edx

       xor    eax, eax
c1:
       add    eax, [ebx]
       add    ebx, 4
       loop   c1

       pop    ebp
       ret    
@SumArrFastCall@8  ENDP
       end

