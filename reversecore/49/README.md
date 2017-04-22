

## IA-32 Register

> Register : CPU 내부에 존재하는 다목적 저장 공간

#### Basic program execution registers
- 범용 레지스터 - General Purpose Registers (32비트 - 8개)
- 세그먼트 레지스터 - Segment Registers ( 16비트 - 6개)
- 프로그램 상태와 컨트롤 레지스터 - Program Status and Control Register ( 32비트 - 1개)
- instruction Pointer ( 32비트 - 1개)

##### 범용 레지스터

산술 연산(ADD, SUB, XOR, OR)명령어에서 상수/변수 값의 저장 용도로 많이 사용
- EAX : Accoumulator for operands and results data (함수 리턴 값에 사용)
- EBX : Pointer to data in DS segment
- ECX : Loop counting
- EDX : I/O pointer

메모리 주소를 저장하는 포인터로 주로 사용
- EBP : Pointer to data on the stack ( in the SS segment)
- ESP : Stack pointer ( in the SS segment)
- ESI : Source pointer for string operations (ESI EDI는 LODS, STOS, REP MOVS와 함께 주로 사용)
- EDI : destination pointer for string operations


#### 세그먼트 레지스터

> Segment : 메모리를 조각내어 각 조각마다 address, range, permission등을 부여해서 메모리를 보호하는 기법. 세그먼트는 페이징 기법과 함께 가상 메모리를 실제 물리 메모리를 변경할 때 사용된다. Segment memory는 SDT(Segment Descriptor Table)이라고 하는 곳에 기술되어 있는데, Segment Register는 바로 이 SDT의 index를 가지고 있다.

보호 모드에서의 Segment memory 모델
- CS : Code segment
- SS : Stack segment
- DS : Data segment
- ES : Extra(Data) segment
- FS : Extra(Data) Segment
- GS : Extra(Data) segment

#### 프로그램 상태와 컨트롤 레지스터
 EFLAGS : Flag Register는 32Bits로 각각의 비트마다 의미를 가지고 있음

- ZF(Zero Flag) : 연산 명령 후에 결과 값이 0이 되면 ZF는 1(True)
- OF(Overflow Flag) : 부호 있는 수 (Signed integer)의 Overflow가 발생했을 때 & MSB(Most Significant Bit)가 변경 되었을 때  1(True)
- Carry Flag(CF) : 부호없는 수 (Unsigned integer)의 Overflow가 발생했을 때 1(True)

#### Instruction Pointer

>EIP(Instruction Pointer) : CPU가 처리할 명령어의 주소를 나타내는 레지스터

CPU는 EIP에 저장된 메모리 주소의 명령어를 하나 처리하고 난 후 자동으로 그 명령어 길이만큼 EIP를 증가시킵니다.
범용 레지스터들과는 다르게 EIP는 그 값을 직접 변경할 수 없고 다른 명령어(JMP, Jcc, CALL, RET, interrup, exception)를 통하여 간접적으로 변경해야 합니다.



-----
Terms
- Stack frame : EBP는 함수가 호출되었을 때 그 순간의 ESP를 저장하고 있다가,
함수가 리턴하기 직전에 다시 ESP에 값을 되돌려줘서 스택이 깨지지 않도록 하는 것

Byte ordering : 데이터를 저장하는 방식
- Big Endian : 사람이 보는 방식과 동일하게 앞에서부터 순차적으로 저장
- Little Endian : 역순으로 저장 - *** Intel x86 CPU ***

TYPE   | Name | SIZE | Big Endian                    | Little Endian
---    | ---  | ---  | ---                           | ---
BYTE   | b    | 1    | [12]                          | [12]
WORD   | w    | 2    | [12] [34]                     | [34] [12]
DWORD  | dw   | 4    | [12] [34] [56] [78]           | [78] [56] [34] [12]
char[] | str  | 6    | [61] [62] [63] [64] [65] [00] | [61] [62] [63] [64] [65] [00]

IA32 레지스터의 종류
- *** Basic program execution registers ***
- x87 FPU registers
- MMX registers
- XMM registers
- Control registers
- Memory management registers
- Debug registers
- Memory type range registers
- Machine specific registers
- Machine check registers
- ...
