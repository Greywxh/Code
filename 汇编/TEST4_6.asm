DATA   SEGMENT       ;定义数据段
    buf db 100 dup(0)
	n db 0
	printInt_div dw 10000,1000,100,10,1
printInt_res db 0,0,0,0,0,"$"
DATA   ENDS
 
CODE   SEGMENT               ;定义代码段
       ASSUME  CS:CODE,DS:DATA
START: 
		MOV  AX,DATA     
        MOV  DS,AX
;----------读入-------------------		
		call init
 
;---------------------------------------------------
;----------排序------------------------------
		call sort
 
;-------------------------------------------------------------
;----------输出------------------------------------
		call output
		
;----------------------------------------------------------------
init:
		call getInt
		mov n,al
		mov bx,0
		mov ch,0
		mov cl,al
	lp:
		push cx
		call getInt
		mov buf[bx],al
		inc bx
		pop cx
		loop lp
	ret
 
sort:
	mov bx,0
	lp1:
		mov di,bx
		inc di
		lp2:
			mov al,buf[bx]
			mov cl,buf[di]
			cmp al,cl
				jae els
				mov buf[bx],cl
				mov buf[di],al
			els:
			
			inc di
			mov ax,di
			mov ah,n
			cmp ah,al
			jae lp2
		inc bx
		cmp bl,n
		jb lp1
ret
 
output:
	mov ch,0
		mov cl,n
		mov bx,0
	lp3:
		mov ah,0
		mov al,buf[bx]
		call putInt
		mov al,' '
		call putchar
		inc bx
		loop lp3
		MOV AH,4CH
        INT 21H   
ret
 
putchar:
	pushf
	push DX
	mov DX,AX
	mov AH,02H
	int 21h
	pop DX
	popf
	ret
 
getInt: 
	;普通输入数字返回输入的数字ax(zf=1),,,特殊情况（esc键和tab键zf=0）esc键返回ax=0(zf=0)，tab返回ax=1(zf=0)
	;可以用jz判断是否发生了特殊情况。用ax区分发生了esc还是tab
 
        push BX  ;保护现场
        push DX 
        push CX 
       ;此处不能pushf，因为flags是返回值
        mov AX,0 ;初始化 
        mov BX,0
        mov CX,0
        mov DX,0
getInt_XUNHUAN:
    mov AH ,01H
    int 21H ; 输入一个字符，一定存储在　AL 中
    cmp  AL,0DH ; 判断回车符　
    jz  getInt_RESULT ;    zf=0 判断是回车
 
    cmp  AL,30H
    jb   getInt_XUNHUAN  ; < 0
    cmp  AL,39H ;<= 9 && > 0
    jbe  getInt_SUM_TO_AX   
 
    jmp  getInt_XUNHUAN ;继续循环　
 
getInt_SUM_TO_AX: 
        mov AH,0 ;清除 AX 高位
		sub AL,30H
        push AX  ;保存 AX
 
        mov AX,CX  ;将原先的值乘以　10 ,实质上乘起来的值放在了 CX 中 
        mov BX,10
        ;如果参数是字节,将把 AL 做乘数, 结果放在 AX
        ;如果参数是字 , 将把 AX 做乘数, 结果放在 DX:AX
        mul BX 
        mov DX,0
        mov CX,AX 
        pop AX
 
        add CX,AX 
        jmp  getInt_XUNHUAN    
getInt_RESULT:
        mov AX,CX
        pop BX  ;恢复现场
        pop DX 
        pop CX
        ret  
 
putInt:
	pushf
	push ax
	push bx
	push cx
	push dx
	push di
	push si
	
    mov  si, offset printInt_div
    mov  di, offset printInt_res                     
    mov  cx,5  
    ddiv:
        mov     dx,0            
        div     word ptr [si]   ;除法指令的被除数是隐含操作数，此处为dx:ax，商ax,余数dx
        add     al,30h           ;商加上48即可得到相应数字的ASCII码
        mov     byte ptr [di],al        
        inc     di                                
        add     si,2                           
        mov     ax,dx                        
        loop    ddiv
        mov     cx,4    
        mov     di, offset printInt_res 
    leadzero:
        cmp     byte ptr [di],'0'   ;不输出前面的0字符    
        jne     pprint
        inc     di                           
        loop    leadzero
    pprint:
        mov     dx,di                       
        mov     ah,9
        int     21h  ;调用DOS功能，该功能为显示DS：DX地址处的字符 
        pop si
        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        popf     
    	RET
CODE  ENDS                    ;代码段结束
END  START              ;汇编结束  