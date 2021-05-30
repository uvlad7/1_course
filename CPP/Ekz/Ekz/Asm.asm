.686
.model flat
.code

PUBLIC _SumStd@8
_SumStd@8 proc
push ebp
mov ebp,esp
mov ecx,[ebp+8] ;число
mov edi,[ebp+12] ;адрес массива
mov ebx, 1
mov esi, 0
cycle1:
inc esi
test ecx, ebx
jz null_
mov [edi + esi*4], ebx
jmp nonull_
null_:
push ebx
mov ebx, 0
mov [edi + esi*4], ebx
pop ebx
nonull_:
shr ecx, 1
cmp ecx, 0
jnz cycle1
mov [edi], esi

pop ebp
ret 8
_SumStd@8 endp


@srar@8 proc 
xor eax, eax 
cmp ecx, 0 
je b 
mov ebx, ecx 
a: 
add eax, [edx] 
add edx, 4 
loop a 
b: 
push eax 
fild dword ptr[esp] 
pop eax 
push ebx 
fidiv dword ptr[esp] 
pop ebx 
ret 
@srar@8 endp
end