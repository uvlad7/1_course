.686
.model flat
.code

PUBLIC @SumFast@8
@SumFast@8 proc
mov eax,ecx ;������ ��������
mov ecx,edx ;������ ��������
add ecx, eax
mov eax,ecx
ret
@SumFast@8 endp

PUBLIC _SumStd@8
_SumStd@8 proc
push ebp
mov ebp,esp
mov ecx,[ebp+8] ;����� �������
mov edi,[ebp+12] ;����� �������
xor eax, eax
xor esi, esi
cycle1:
add eax, [edi + 4*esi]
inc esi
loop cycle1
pop ebp
ret 8
_SumStd@8 endp



end