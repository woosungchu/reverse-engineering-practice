# abex' crackme

#### Source code
```
Address   Hex dump          Command                                  Comments
00401000  /$  6A 00         PUSH 0                                   ; /Type = MB_OK|MB_DEFBUTTON1|MB_APPLMODAL
00401002  |.  68 00204000   PUSH OFFSET 00402000                     ; |Caption = "abex' 1st crackme"
00401007  |.  68 12204000   PUSH OFFSET 00402012                     ; |Text = "Make me think your HD is a CD-Rom."
0040100C  |.  6A 00         PUSH 0                                   ; |hOwner = NULL
0040100E  |.  E8 4E000000   CALL <JMP.&USER32.MessageBoxA>           ; \USER32.MessageBoxA
00401013  |.  68 94204000   PUSH OFFSET 00402094                     ; /RootPath = "c:\"
00401018  |.  E8 38000000   CALL <JMP.&KERNEL32.GetDriveTypeA>       ; \KERNEL32.GetDriveTypeA
0040101D  |.  46            INC ESI
0040101E  |.  48            DEC EAX
0040101F  |.  EB 00         JMP SHORT 00401021
00401021  |>  46            INC ESI
00401022  |.  46            INC ESI
00401023  |.  48            DEC EAX
00401024  |.  3BC6          CMP EAX,ESI
00401026  |.  74 15         JE SHORT 0040103D
00401028  |.  6A 00         PUSH 0                                   ; /Type = MB_OK|MB_DEFBUTTON1|MB_APPLMODAL
0040102A  |.  68 35204000   PUSH OFFSET 00402035                     ; |Caption = "Error"
0040102F  |.  68 3B204000   PUSH OFFSET 0040203B                     ; |Text = "Nah... This is not a CD-ROM Drive!"
00401034  |.  6A 00         PUSH 0                                   ; |hOwner = NULL
00401036  |.  E8 26000000   CALL <JMP.&USER32.MessageBoxA>           ; \USER32.MessageBoxA
0040103B  |.  EB 13         JMP SHORT 00401050
0040103D  |>  6A 00         PUSH 0                                   ; /Type = MB_OK|MB_DEFBUTTON1|MB_APPLMODAL
0040103F  |.  68 5E204000   PUSH OFFSET 0040205E                     ; |Caption = "YEAH!"
00401044  |.  68 64204000   PUSH OFFSET 00402064                     ; |Text = "Ok, I really think that your HD is a CD-ROM! :p"
00401049  |.  6A 00         PUSH 0                                   ; |hOwner = NULL
0040104B  |.  E8 11000000   CALL <JMP.&USER32.MessageBoxA>           ; \USER32.MessageBoxA
00401050  \>  E8 06000000   CALL <JMP.&KERNEL32.ExitProcess>         ; \KERNEL32.ExitProcess
00401055   $- FF25 50304000 JMP DWORD PTR DS:[<&KERNEL32.GetDriveTyp
0040105B   $- FF25 54304000 JMP DWORD PTR DS:[<&KERNEL32.ExitProcess
00401061   $- FF25 5C304000 JMP DWORD PTR DS:[<&USER32.MessageBoxA>]
```

1. CALL JMP.&KERNEL32.GetDriveTypeA
2. CMP EAX,ESI : EAX(1)와 ESI(2) 비교
3. JE SHORT 0040103D :JE(Jump if Equal) ? JMP 40103D : 401028


#### Patch and Crack

> Assemble(space) 0040101F to 'JMP SHORT 0040103D'




----
Terms
- PUSH : 스택에 값을 입력
- CALL : 지정된 주소의 함수를 호출
- INC : 값을 1 증가
- DEC : 값을 1 감소
- JMP : 지정된 주소로 점프
- CMP : 주어진 두 개의 operand 비교 (*SUB 명령어와 동일하나 operand의 값이 변경되지 않고 EFLAGS 레지스터만 변경됨 - 두 operand 값이 동일하다면 SUB 결과는 0이고 ZF = 1 로 세팅됨)
- JE : 조건 분기 (Jump if equal) * ZF = 1 이면 점프

스택 메모리는 FILO이기 때문에 역순으로 파라미터가 넘어간다
```
00401000  /$  6A 00         PUSH 0                                   ; /Type = MB_OK|MB_DEFBUTTON1|MB_APPLMODAL
00401002  |.  68 00204000   PUSH OFFSET 00402000                     ; |Caption = "abex' 1st crackme"
00401007  |.  68 12204000   PUSH OFFSET 00402012                     ; |Text = "Make me think your HD is a CD-Rom."
0040100C  |.  6A 00         PUSH 0                                   ; |hOwner = NULL
0040100E  |.  E8 4E000000   CALL <JMP.&USER32.MessageBoxA>           ; \USER32.MessageBoxA
```
