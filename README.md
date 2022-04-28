<img align="left" width="80" height="80" src="https://github.com/vy-nguyenlethao0510/HCMUT_CSE_POS_2.0/blob/hai/SoftwareReport/R/REPORT/Logo-BK.png">

# HCMUT-CA_VM
Hello everyone, this is my short implementation of a MIPS Virtual Machine in C++.

## Briefing
Using C++ programming language, we built a Virtual Machine (VM) that can compile user input MIPS instruction. 
Before getting our hands dirty, let's first sketch out how the VM works. By having the power of the programming language, we could simplify the operation the MIPS architecture computer. Our VM could support R-type instructions such as add, sub, and, or,...; I-type instructions and the jump instruction. However, due to the lack of resources on the programming language, we couldn't implement all of the instruction with unsigned element like addiu, lbu,... When consider to add this function or not, we have tried our best to describe the data structure for the register but with the unsigned instructions, these make the VM way to complex to design so we decided to odd these instruction out.<br />
The implementation of the VM on C++ proves a great challenge for us. It combines all of our knowledge from previous subjects like DSA, CA,... The VM will take the user input from a text file and return a text file which contains the list of registers that values have been changed during the execution of the operation. The VM is implemented based on the single cycle model. In each cycle, one instruction is execute, the program counter is incremented and then move to the next instruction in the next cycle. Below is a simple diagram showing how our VM works.<br />

<p align="center">
  <img src="https://github.com/leloc0609/HCMUT-CA_VM/blob/main/img/LDpowerpoint-Page-3.png" />
</p>

## Input syntax
Our implementation simplifies some of the MIPS standard instruction syntax as shown below. The reason for us to do so is because of the complexity it can cause for C++ program to handle string, which in return can make our VM run slower when dealing with complex strings.<br />

<p align="center">
  <img src="https://github.com/leloc0609/HCMUT-CA_VM/blob/main/img/chap3.4_VM_2.png" />
</p>
The difference in this new syntax is that we removes the \$ symbol before the register and we change the offset number to be placed after the register for ease of implementation. On the website, we may include instruction for users to know our syntax before using the VM. Users will put their code in the web, then it will be converted into a text file name input.txt by the VM.

## Components of VM
The VM is implemented as a object in C++ which has these following component:
* Instruction* ins\_mem: this is used to storing the instruction;
* typeReg reg: the data structure of implementing the register;
* size\_instr: variable to store the number of instruction from input file;
* PC: program counter;
* long int memory: main memory of the VM;
* userDefineNameVar varStore: for storing the user define variable information.
* userDefineLabel labelStore: for storing the user define label.
* curVar: the current index of user define variable.
* curLabel: the current index of user define variable.
* curAdd: the current address in the memory.
