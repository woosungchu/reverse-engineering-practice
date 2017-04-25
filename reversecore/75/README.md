# Stack Frame

> 스택 프레임은 ESP가 아닌 EBP(베이스 포인터) 레지스터를 사용하여 스택 내의 로컬 변수, 파라미터, 복귀 주소에 접근하는 기법. PUSH EBP

```
PUSH EBP        ; 함수 시작(EBP를 사용하기 전에 기존의 값을 스택에 저장)
MOV EBP,ESP     ; 현재의 ESP 값을 EBP에 저장

...             ; 함수 본체에서 ESP가 변경되더라도 EBP가 변경되지 않으므로
                ; 안전하게 로컬 변수와 파라미터를 엑세스할 수 있음

MOV ESP, EBP    ; ESP를 정리 (함수 시작했을 때의 값으로 복원시킴)
POP EBP         ; 리턴되기 전에 저장해 놓았던 원래 EBP 값으로 복원
RETN            ; 함수 종료
```



----
#### Assembly
```
CPU Disasm
Address   Hex dump          Command                                  Comments
00401000  /$  55            PUSH EBP                                 ; # add()
00401001  |.  8BEC          MOV EBP,ESP
00401003  |.  83EC 08       SUB ESP,8
00401006  |.  8B45 08       MOV EAX,DWORD PTR SS:[ARG.1]             ; [EBP+8] => param 'a'
00401009  |.  8945 F8       MOV DWORD PTR SS:[LOCAL.2],EAX           ; [EBP-8] => local 'x'
0040100C  |.  8B4D 0C       MOV ECX,DWORD PTR SS:[ARG.2]             ; [EBP+C] => param 'b'
0040100F  |.  894D FC       MOV DWORD PTR SS:[LOCAL.1],ECX           ; [EBP-4] => local 'y'
00401012  |.  8B45 F8       MOV EAX,DWORD PTR SS:[LOCAL.2]
00401015  |.  0345 FC       ADD EAX,DWORD PTR SS:[LOCAL.1]
00401018  |.  8BE5          MOV ESP,EBP
0040101A  |.  5D            POP EBP
0040101B  \.  C3            RETN
0040101C      CC            INT3
0040101D      CC            INT3
0040101E      CC            INT3
0040101F      CC            INT3
00401020  /$  55            PUSH EBP                                 ; #main()
00401021  |.  8BEC          MOV EBP,ESP
00401023  |.  83EC 08       SUB ESP,8                                ; long type은 각 4byte
00401026  |.  C745 FC 01000 MOV DWORD PTR SS:[LOCAL.1],1             ; [EBP-4] => local 'a'
0040102D  |.  C745 F8 02000 MOV DWORD PTR SS:[LOCAL.2],2             ; [EBP-8] => local 'b'
00401034  |.  8B45 F8       MOV EAX,DWORD PTR SS:[LOCAL.2]
00401037  |.  50            PUSH EAX                                 ; /Arg2 => 2
00401038  |.  8B4D FC       MOV ECX,DWORD PTR SS:[LOCAL.1]           ; |
0040103B  |.  51            PUSH ECX                                 ; |Arg1 => 1
0040103C  |.  E8 BFFFFFFF   CALL 00401000                            ; \StackFrame.00401000, add()
00401041  |.  83C4 08       ADD ESP,8
00401044  |.  50            PUSH EAX
00401045  |.  68 84B34000   PUSH OFFSET 0040B384                     ; ASCII "%d"
0040104A  |.  E8 18000000   CALL 00401067                            ; printf()
0040104F  |.  83C4 08       ADD ESP,8
00401052  |.  33C0          XOR EAX,EAX
00401054  |.  8BE5          MOV ESP,EBP
00401056  |.  5D            POP EBP
```

#### DWORD PTR

어셈블리 언어   | C 언어 | Type casting |
---    | ---  | ---  |
DWORD PTR SS:[EBP-4]  | *(DWORD*)(EBP-4)   | DWROD (4 바이트)  
WORD PTR SS:[EBP-4]   | *(WORD*)(EBP-4)    | WORD (4 바이트)   
BYTE PTR SS:[EBP-4]   | *(BYTE*)(EBP-4)    | BYTE (4 바이트)   
