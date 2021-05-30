      .386
      .model flat
      .data
      .code
;       PUBLIC _SumArr
;_SumArr PROC  
       PUBLIC SumArr
SumArr PROC   c
       push   ebp
       mov    ebp, esp
       push   ebx

       mov    ebx, [ebp+08h]
       mov    ecx, [ebp+0Ch]

       xor    eax, eax
c1:
       add    eax, [ebx]
       add    ebx, 4
       loop   c1
       
       pop    ebx
       pop    ebp
       ret        // Стек освобождает вызывающая программа (поэтому просто ret)
;_SumArr  ENDP
SumArr  ENDP

       end