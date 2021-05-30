.386
PUBLIC @Sum@16
.model flat
.data 
 ;c dd ?
 ;b dd ?
 ;m dd ?
 ;s dd 0
 
 .code
@Sum@16 proc
  push ebp
  mov ebp,esp

  push ebx
  push esi
  
  ;mov c,[ebp+8]
  mov ebx,ecx              ;c

  ;mov b,[ebp+12]
  ;mov b,edx              ;b

  mov ecx,[ebp+12]
  ;mov m,[ecx]              ; m

  xor eax,eax
  mov esi,[ebp+8];adres 1 elementa massiva
m1:  cmp [esi],ebx
  jl ignor
  cmp [esi],edx
  jg ignor
  add eax,[esi]
ignor:  
  add esi,4
  loop m1
      
  ;mov eax,s
  pop esi
  pop ebx
  pop ebp
  ret 8
@Sum@16 endp
  end