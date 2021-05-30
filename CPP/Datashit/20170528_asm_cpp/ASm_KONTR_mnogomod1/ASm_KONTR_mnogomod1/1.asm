.486
PUBLIC @Sum@16
.model flat
.data 
 c dd ?
 b dd ?
 m dd ?
 s dd 0
 
 .code
@Sum@16 proc
push ebp
mov ebp,esp

;mov c,[ebp+8]
mov c,ecx              ;c

;mov b,[ebp+12]
mov b,edx              ;b

mov ecx,[ebp+16]
;mov m,[ecx]              ; m

xor eax,eax
mov esi,[ebp+20];adres 1 elementa massiva
       m1:  cmp [esi],c
			  jl ignor
			  cmp [esi],b
			      jg ignor
				   add eax,[esi]
			ignor:  add esi,4
       loop m1
      
	mov eax,s
	pop ebp
	ret 
	@Sum@16 endp
	end