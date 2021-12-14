#include"Operation.h"

void fetch_func(Instruction*t){
	if (t->ins.compare("add")) t->func = &add;    
}

void add(Instruction *t){
    cout << "hello";
}