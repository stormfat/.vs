//不可重载的操作符:: .* . ?:

#include <iostream>

using namespace std;

class Person
{
	//重载加法操作符.
 public:
        void operator+(const Person& rhs) {
          cout << "执行重载的加法操作" << endl;
		}
};

int main() {
  Person p1, p2;
  p1 + p2;
  cout << "hello" << endl;
  return 0;
}