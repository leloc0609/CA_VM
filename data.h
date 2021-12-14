#include "main.h"
using namespace std;
#define R 1
#define I 2
#define J 3

class data{
  public:
    int x;
    float y;
    int type;
  public: //Own operation
    void take_data(string s,int n);
};

class Instruction{
  public:
    int type;
    string instruction;
    int rs,rt,rd;
    string ins,o1,o2,o3;
    int numOp{0};
    void (*func)(Instruction*);
  public:
    Instruction(string ins){
      this->instruction = ins;
      rs=-1,rt=-1,rd=-1;
    }
    void exec(){
      func(this);
    }
};