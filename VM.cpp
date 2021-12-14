#include "VM.h"

using namespace std;
void VM::check_error(string s,int n){

}

int VM::read_file(string filename){
 	ifstream re_f;
	re_f.open(filename);
	int n = 0;
	if (re_f.fail()) return 0;
	while (!re_f.eof()) {
		char tmp[256];
		re_f.getline(tmp, 256, '\n');
		mem_bank[n] = tmp;
		ins_mem[n] = new Instruction(tmp);
		seperate_ins(ins_mem[n]);
		n++;
	}
	re_f.close();
	return n;
}
int get_registor(string s){
	if (s.compare("a0")) return 0;
	if (s.compare("a1")) return 1;
	if (s.compare("a2")) return 2;
	if (s.compare("a3")) return 3;
	if (s.compare("t0")) return 4;
	if (s.compare("t1")) return 5;
	if (s.compare("t2")) return 6;
	if (s.compare("t3")) return 7;
	if (s.compare("t4")) return 8;
	if (s.compare("t5")) return 9;
	if (s.compare("t6")) return 10;
	if (s.compare("t7")) return 11;
	if (s.compare("t8")) return 12;
	if (s.compare("t9")) return 13;
	if (s.compare("s0")) return 14;
	if (s.compare("s1")) return 15;
	if (s.compare("s2")) return 16;
	if (s.compare("s3")) return 17;
	if (s.compare("s4")) return 18;
	if (s.compare("s5")) return 19;
	if (s.compare("s6")) return 20;
	if (s.compare("s7")) return 21;
	if (s.compare("v0")) return 22;
	if (s.compare("v1")) return 23;
}


void VM::seperate_ins(Instruction* ins){
	int numOp=0;
	string temp = ins->instruction;
	string t0 = temp.substr(0,temp.find(" "));
	ins->ins= t0;
	temp = temp.erase(0,temp.find(" ")+1);
	string t1,t2,t3;
	if (temp.find(" ")==string::npos){
		t1= temp;
		ins->o1 = t1; 
		numOp=1;
		ins->numOp=numOp;
	}
	else{
		t1 = temp.substr(0,temp.find(" "));
		temp = temp.erase(0,temp.find(" ")+1);
		if (temp.find(" ")==string::npos){
			t2= temp;
			ins->o2 = t2; 
			numOp=2;
			ins->numOp = numOp;
		}
		else{
			t2=temp.substr(0,temp.find(" "));
			temp = temp.erase(0,temp.find(" ")+1);
			t3= temp;
			ins->o3 = t3; 
			numOp=3;
			ins->numOp = numOp;
		}
	}
}

void VM::run(string filename)
{
	VM::size_instr = read_file(filename);
	while(VM::IP < VM::size_instr){
		fetch_func(ins_mem[IP]);
		ins_mem[IP]->exec();
		VM::IP++;
	}

}
