## ReverseCore

OllyDbg
- Code Window : disassembly codes
- Register Window : CPU Register
- Dump Window : memery address in Hex, ASCII
- Stack Window : process stack memory pointed by ESP register

EP : Enty Point(Start point)
- Address : Virtual address of process (ex: 000411A0)
- Instruction : IA32 or x86 CPU order (ex: E8 6715000)
- Disassembled code : assembled OP code for easier viewing
- comment : comments depend on options

Ollydbg Shortcut
- [ CTRL+F2 ] : restart
- [ F7 ] : step into
- [ F8 ] : step over
- [ CTRL+F9 ] : retn


- [ CTRL+G ] : Go to (without running)
- [ F4 ] : Go to (with running)
- [ ;  ] : comments
- [ : ] : add label
- [ F2 ] : toggle Breakpoin
- [ F9 ] : run
- [ \* ] : show current EIP
- [ \- ] : show previous cursor
- [ ENTER ] : preview call/jmp address

Debugging
- red comments is name of function
- arguments can be seen in comments

Four ways to base-camping
1. [ CTRL+G , F4 ] - Go to address and Execute till cursor
2. [ F2 , F9 ] - Breakpoint and run ( ALT+B for breakpoint list )
3. [ ; ] - Add comments and find user-defined-comments by right click
4. [ : ] - Set Label

Four ways to find the Code you want quickly
1. Repeat [ F8 ] and wait for action
2. Search for all referenced text strings
3. Search for all intermodular calls ( API such as Win32 API )
4. Search for name is all modules ( or just 'Names') - set BP on *.dll directly
