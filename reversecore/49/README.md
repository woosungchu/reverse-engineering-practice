# Little Endian

Byte ordering : 데이터를 저장하는 방식
- Big Endian : 사람이 보는 방식과 동일하게 앞에서부터 순차적으로 저장
- Little Endian : 역순으로 저장 - *** Intel x86 CPU ***

TYPE   | Name | SIZE | Big Endian                    | Little Endian
---    | ---  | ---  | ---                           | ---
BYTE   | b    | 1    | [12]                          | [12]
WORD   | w    | 2    | [12] [34]                     | [34] [12]
DWORD  | dw   | 4    | [12] [34] [56] [78]           | [78] [56] [34] [12]
char[] | str  | 6    | [61] [62] [63] [64] [65] [00] | [61] [62] [63] [64] [65] [00]
