# Stack

- 함수 내의 로컬 변수 임시 저장
- 함수 호출 시 파라미터 전달
- 복귀 주소 (return address) 저장

#### 동작 원리

CODE WINDOW
```
00401000 PUSH 100
00401005 POP EAX
00401006 NOP
```
Stack Window
>Stack에 값을 입력하면 ESP(스택 포인터)는 감소하고, Stack에 값을 꺼내면 ESP는 증가한다

```
0018FF88 00000000
-0018FF8C 792F336A Return to kernel32.BaseThreadInitThunk

#Run 00401000

-0018FF88 00000100
0018FF8C 771B1174 Return to kernel32.BaseThreadInitThunk

#Run 00401005

0018FF88 00000100
-0018FF8C 771B1174 Return to kernel32.BaseThreadInitThunk
```



----

Terms
- ESP : Stack Pointer - Bottom(0018FF8C) to Top(0018FF88)

Register Window
```
EAX 762F3358 kernel32.BaseThreadInitThunk
ESP 0018FF8C

#Run 00401000

EAX 762F3358 kernel32.BaseThreadInitThunk
ESP 0018FF88
EIP 00401005

#Run 00401005

EAX 00000100
EDX 00401000 Stack.<ModuleEntryPoint>
ESP 0012FF8C
P 1 CS 001B 32bit
```
