      .386
      .model flat
      .code
       ;PUBLIC C DoTotal
       PUBLIC _DoTotal
_DoTotal PROC
       push   ebp
       mov    ebp, esp

       mov    eax, [ebp+08h]
       add    eax, [ebp+0Ch]

       pop    ebp
       ret
_DoTotal  ENDP

       end
