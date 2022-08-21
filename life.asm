.model tiny
.code

start:
xor dx, dx
mov ax, 3
int 10h
mov ax, 0b800h
mov es, ax
mov ds, ax
mov al, 10h
xor ah, ah
mov di, 160
mov cx, 162
j20:inc di
inc di
mov es:[di], al
cmp di, 500
jz super_loop
jmp j20


super_loop:
mov ah, 86h
mov cx, 1
mov dx, 0fff0h
int 15h
xor ah, ah
mov cx, 162
some_loop:xor dx, dx
mov di, cx
mov al, 10h
call countof
mov al, 46
call countof
a20:
cmp dx, 3
jz b20
b21:
cmp dx, 2
jz b22
mov al, 10h
cmp es:[di], al
jnz b22
mov al, 46
mov es:[di], al
b22:
xor dx, dx
inc cx
inc cx
cmp cx, 3840
jz c20
jnz some_loop

n20:jmp super_loop

b20:mov al, 10h
cmp es:[di], al
jz b22
mov al, 7h
mov es:[di], al
jmp b22

c20:mov cx, 162
some_loop2:
mov di, cx
mov al, 46
cmp es:[di], al
jz c21
c22:mov al, 7h
cmp es:[di], al
jz c23
c24:
inc cx
inc cx
cmp cx, 3840
jz n20
jmp some_loop2

c21:mov al, 0h
mov es:[di], al
jmp c24

c23:mov al, 10h
mov es:[di], al
jmp c24

exit_loop:
mov ah, 4ch
int 21h
countof proc
add di,160
cmp es:[di], al
jnz a21
inc dx
a21:
add di, 2
cmp es:[di], al
jnz a22
inc dx
a22:sub di, 160
cmp es:[di], al
jnz a23
inc dx
a23:sub di, 160
cmp es:[di], al
jnz a24
inc dx
a24:sub di, 2
cmp es:[di], al
jnz a25
inc dx
a25:sub di, 2
cmp es:[di], al
jnz a26
inc dx
a26:add di, 160
cmp es:[di], al
jnz a27
inc dx
a27:add di, 160
cmp es:[di], al
jnz a28
inc dx
a28:mov di, cx
ret
countof endp
end start
