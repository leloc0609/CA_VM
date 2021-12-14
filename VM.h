#ifndef VM_H
#define VM_H

#include "main.h"
#include "data.h"
#include "Operation.h"

class VM
{
public:
    string **cut_ins;
    vector<int>stack_label;
    string *mem_bank;
    data *sta_mem;
    data *register_CPU;
    Instruction* ins_mem[65536];
public:
    bool is_input;
    int size_instr;  
    int IP; // address
public:
  VM(){
   this->sta_mem = new data[65536];
   /*
   a0 -a3 : 0->3 
   t0 - t9: 4-> 13
   s0 - s7: 14 ->21
   v0, v1:  22,23  
   */
   VM::IP = 0;
   VM::size_instr = 0;
   VM::is_input = false;
   
   this->register_CPU = new data[24];
   this->mem_bank = new string[65536];
   this->cut_ins = new string *[65536];
  }
  ~VM(){
     // Delete everything
      for(int i =0; i < size_instr;i++){
          delete[]cut_ins[i];
      }
      delete[]cut_ins;
      VM::IP = 0;
      VM::size_instr = 0;
      VM::is_input = false;
      delete[]sta_mem;
      delete[]register_CPU;
      delete[]mem_bank;
      is_input = false;
  }
  

  void check_error(string,int);
  int read_file(string filename);
  void run(string filename);
  void seperate_ins(Instruction* ins);
};

#endif