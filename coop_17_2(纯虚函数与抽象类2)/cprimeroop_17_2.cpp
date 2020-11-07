#include <iostream>
#include <string>
using namespace std;

enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };

class Animal {
 public:
  Animal(int age) : itsAge(age) { cout << "Animal构造函数被调用...\n"; }
  virtual ~Animal() { cout << "Animal析构函数被调用...\n"; }
  virtual int GetAge() { return itsAge; }
  virtual void SetAge(int age) { itsAge = age; }
  virtual void Sleep() const = 0;
  virtual void Eat() const = 0;
  virtual void Reproduce() const = 0;
  virtual void Move() const = 0;
  virtual void Speak() const = 0;

 private:
  int itsAge;
};

class Mammal
    : public Animal {  //没有覆盖基类的所有纯虚函数,所以还是个抽象类.(因为它继承了基类的纯虚函数)
 public:
  Mammal(int age) : Animal(age) { cout << "Mammal构造函数被调用...\n"; }
  virtual ~Mammal() { cout << "Mammal析构函数被调用...\n"; }
  virtual void Reproduce() const {
    cout << "Mammal reproduction depicted...\n";
  }
};

class Fish : public Animal {
 public:
  Fish(int age) : Animal(age) { cout << "Fish的构造函数被调用...\n"; }
  virtual ~Fish() { cout << "Fish的析构函数被调用...\n"; }
  virtual void Sleep() const { cout << "fish snoring...\n"; }
  virtual void Eat() const { cout << "fish feeding...\n"; }
  virtual void Reproduce() const { cout << "fish laying eggs...\n"; }
  virtual void Move() const { cout << "fish swimming...\n"; }
  virtual void Speak() const {}
};

class Horse : public Mammal {
 public:
  Horse(int age, COLOR color) : Mammal(age), itsColor(color) {
    cout << "Horse构造函数被调用...\n";
  }
  virtual ~Horse() { cout << "Horse的析构函数被调用...\n"; }
  virtual void Speak() const { cout << "Whinny!...\n"; }
  virtual void Sleep() const { cout << "Horse snoring...\n"; }
  virtual COLOR getColor() const { return itsColor; }
  virtual void Eat() const { cout << "Horse feeding...\n"; }
  virtual void Move() const { cout << "Horse running...\n"; }

 protected:
  COLOR itsColor;
};

class Dog : public Mammal {
 public:
  Dog(int age, COLOR color) : Mammal(age), itsColor(color) {
    cout << "Dog的构造函数被调用...\n";
  }
  virtual void Speak() const { cout << "whoof!...\n"; }
  virtual void Sleep() const { cout << "Dog snoring...\n"; }
  virtual void Eat() const { cout << "Dog eating...\n"; }
  virtual void Move() const { cout << "Dog running...\n"; }
  virtual void Reproduce() const { cout << "dog sreproducing...\n"; }

 protected:
  COLOR itsColor;
};

int main() {
  Animal *pAnimal = nullptr;
  int choice;
  bool fQuit = false;
  while (fQuit == false) {
    cout << "(1)Dog (2)Horse (3)Fish (0)Quit:";
    cin >> choice;
    switch (choice) {
      case 1:
        pAnimal = new Dog(2, Yellow);
        break;
      case 2:
        pAnimal = new Horse(3, Blue);
        break;
      case 3:
        pAnimal = new Fish(1);
        break;
      case 0:
        fQuit = true;
        break;
      default:
        break;
    }
    if (nullptr!=pAnimal) {
      pAnimal->Speak();
      pAnimal->Eat();
      pAnimal->Reproduce();
      pAnimal->Move();
      pAnimal->Sleep();
      delete pAnimal;
      cout << endl;
    }
  }

  return 0;
}