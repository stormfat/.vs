#pragma once
#include <iostream>

using namespace std;
enum BREED { GOLDEN,
    CAIRN,
    DANDIE,
    SHETLAND,
    DOBERMAN,
    LAB };

class Mammal {
public:
    Mammal();
    ~Mammal();
    int getAge() const { return itsAge; }
    void setAge(int age) { itsAge = age; }
    int getWeight() const { return itsWeight; }
    void setWeight(int Weight) { itsWeight = Weight; }

    void Speak() const { cout << "Mammal的声音!\n"; }
    void Sleep() const { cout << "Mammal正在睡觉!\n"; }

protected:
    int itsAge;
    int itsWeight;
};

class Dog : public Mammal {
public:
    Dog();
    ~Dog();
    BREED getBreed() const { return itsBreed; }
    void SetBreed(BREED breed) { itsBreed = breed; }
    void WagTail() const { cout << "狗摇尾巴!\n"; }
    void BegForFood() const { cout << "狗要吃饭!\n"; }

private:
    BREED itsBreed;
};

Mammal::Mammal()
    : itsAge(3)
    , itsWeight(5)
{
    cout << "Mammal的构造函数被调用!" << endl;
}
Mammal::~Mammal() { cout << "Mammal的析构函数被调用!" << endl; }

Dog::Dog()
    : itsBreed(GOLDEN)
{
    cout << "Dog的构造函数被调用!" << endl;
}
Dog::~Dog() { cout << "Dog的析构函数被调用!" << endl; }
