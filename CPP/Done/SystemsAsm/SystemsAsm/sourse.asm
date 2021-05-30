.686
.model flat
.data
regs dd 10 dup(?); массив для содержимого регистров
sysosn dd 10 dup(?); массив для оснований с. с.
colregs dd ?
colsystems dd ?
outp db 200 dup(?); массив для вывода
osn dd ?
len dd ?
.code
 PUBLIC _Syst
_Syst proc
push ebp
mov ebp,esp

mov esi,  [ebp+8]
mov edi, [esi]
mov eax, [edi]
mov colregs, eax
mov edi, [esi+4]
mov eax, [edi]
mov colsystems, eax

mov ecx, 0
xor edi, edi
cycle0:
mov edi, [esi+8+ecx*4]
mov eax, [edi]
mov sysosn[ecx*4], eax
inc ecx
cmp ecx, colsystems
jl cycle0

mov ecx, colregs
xor esi, esi
cycle:
mov eax, [ebp+12+esi*4]
mov regs[esi*4], eax
inc esi
loop cycle

mov len, 1
mov ecx, colregs
mov esi, colregs
dec esi

cycle1: ;по значениям
mov eax, regs[esi*4];значение
push ecx
push esi

mov ecx, colsystems;кол-во систем
mov esi, colsystems
dec esi

cycle2: ;по основаниям
push eax
delim:
cdq
idiv sysosn[esi*4]
cmp edx, 9
jg letter
add edx, 48
jmp number
letter:
add edx, 55
number:
mov edi, len
mov outp[edi], dl
inc len
cmp eax, 0
jg delim

mov edi, len
mov dl, ' '
mov outp[edi], dl
inc len
pop eax
dec esi
loop cycle2

pop esi
dec esi
pop ecx
loop cycle1

dec len
dec len
mov eax, len
mov outp, al
lea eax, outp
pop ebp
ret
_Syst endp
 
 end