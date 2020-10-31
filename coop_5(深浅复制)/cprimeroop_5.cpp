#include <iostream>
#include <cstring>
using namespace std;

class CDemo {
 public:
  CDemo(int pa,const char* cstr) {
    this->a = pa;
    this->str = new char[1024];
    strcpy(this->str, cstr);
  }

 public:
  int a;
  char* str;
};

int main() {
  
  CDemo A(10, "hello");
  return 0;
}