      .386
      .model flat
      .data
      .code
       PUBLIC _SumArrStdCall@8
_SumArrStdCall@8 PROC
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
_SumArrStdCall@8  ENDP
       end

