.386
.model flat
.data 
c1 dd ?
 b dd ?
 .code
 PUBLIC _Sum
 _Sum proc 
push ebp
mov ebp,esp
push edi
push esi
push ebx


  mov edi,[ebp+16]  ; c - edi
  ;mov c,ecx              ;c

  mov ebx,[ebp+20]    ; b - ebx
  ;mov b,edx              ;b

  mov ecx,[ebp+12]
  ;mov m,[ecx]              ; m ??????

  xor eax,eax
  mov esi,[ebp+8]   ;adres 1 elementa massiva
m1: 
  cmp [esi],edi
  jl ignor      ; a[i] ? c
  cmp [esi],ebx   ; a[i] ? b
  jg ignor
  add eax,[esi] 
ignor:    ; a[i] < c или a[i]>b
  add esi,4
  loop m1
  pop ebx
  pop esi
  pop edi
  pop ebp
  ret 
_Sum endp
 end