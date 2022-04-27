# HCMUT-CA_VM
Hello everyone, this is my short implementation of a MIPS Virtual Machine in C++.

Using C++ programming language, I built a Virtual Machine (VM) that can compile user input MIPS instruction.
Before getting our hands dirty, let’s first sketch out how the VM works. By having the power of the
programming language, we could simplify the operation the MIPS architecture computer. Our VM
could support R-type instructions such as add, sub, and, or,...; I-type instructions and the jump
instruction. However, due to the lack of resources on the programming language, we couldn’t
implement all of the instruction with unsigned element like addiu, lbu,... When consider to add
this function or not, we have tried our best to describe the data structure for the register but with
the unsigned instructions, these make the VM way to complex to design so we decided to odd
these instruction out.
The implementation of the VM on C++ proves a great challenge for us. It combines all of our
knowledge from previous subjects like DSA, CA,... The VM will take the user input from a text file
and return a text file which contains the list of registers that values have been changed during the
execution of the operation. The VM is implemented based on the single cycle model. In each
cycle, one instruction is execute, the program counter is incremented and then move to the next
instruction in the next cycle. Below is a simple diagram showing how our VM works.

