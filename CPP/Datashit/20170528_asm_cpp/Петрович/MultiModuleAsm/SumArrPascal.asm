      .386
      .model flat
      .data
      .code
       PUBLIC SUMARRPASCAL
SUMARRPASCAL PROC                  ;  __pascal
       push   ebp
       mov    ebp, esp

       mov    ebx, [ebp+0Ch]
       mov    ecx, [ebp+08h]

       xor    eax, eax
c1:
       add    eax, [ebx]
       add    ebx, 4
       loop   c1

       pop    ebp
       ret    08h
SUMARRPASCAL  ENDP
       end

