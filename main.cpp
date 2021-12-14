#include "main.h"

void test(string filename) {
    VM *vm = new VM();
    try {
        vm->run(filename);
    }
    catch (exception& e) {
        cout << e.what();
    }
    delete vm;
}


int main(int argc, char **argv)
{ 
  string a = "test1.txt";
  test(a);
  return 0;
}