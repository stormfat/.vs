/*学习内容:
多继承
多继承中的二义性问题(重点,用虚基类来解决)
虚基类:由底層的派生類直接構造最頂層的基類,而中間層的派生類不去構建基類,由此避免出現下級派生類產生二義性.
虚基类的构造函数
實際運用中,盡量不用多繼承,而且單繼承完全可以做到同樣效果,java之類就抛棄了多繼承*/

#include <iostream>
using std::auto_ptr;
using std::cout;
using std::endl;
using std::string;

enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };

class Animal {
 public:
  Animal(int);
  virtual ~Animal() { cout << "Animal的析構函數被調用\n"; }
  virtual int GetAge() { return itsAge; }
  virtual void SetAge(int age) { itsAge = age; }

 private:
  int itsAge;
};
Animal::Animal(int age) : itsAge(age) { cout << "Animal的構造函數被調用\n"; }

class Horse : virtual public Animal {
 public:
  Horse(int height, COLOR color, int age);
  virtual ~Horse() { cout << "Horse的析构函数被调用\n"; }
  virtual void Whinny() const { cout << "Whinny!..."; }
  virtual int GetHeight() const { return itsHeight; }
  virtual COLOR GetColor() const { return itsColor; }

 private:
  int itsHeight;
  COLOR itsColor;
};

Horse::Horse(int height, COLOR color, int age)
    : itsHeight(height), itsColor(color), Animal(age) {
  cout << "Horse的构造函数被调用\n";
}
class Bird : virtual public Animal {  //虛基類(虛繼承),表示Horse不構造Animal
 public:
  Bird(bool migrates, COLOR color, int);
  virtual ~Bird() { cout << "Bird的析构函数被调用\n"; }
  virtual void Chirp() const { cout << "Chirp..."; }
  virtual void Fly() const { cout << "I can fly!"; }
  virtual bool GetMigrates() { return itsMigration; }
  virtual COLOR GetColor() const { return itsColor; }

 private:
  bool itsMigration;
  COLOR itsColor;
};
Bird::Bird(bool migrates, COLOR color, int age)
    : itsMigration(migrates), itsColor(color), Animal(age) {
  cout << "Bird的构造函数被调用\n";
}

class Pegasus : public Horse, public Bird {
 public:
  void Chirp() const {
    Whinny();
  }  //继承了Bird基类的Chirp(),用Horse基类的Whinny()进行覆盖
  Pegasus(COLOR, int, bool, long, int);
  ~Pegasus() { cout << "Pegasus析构函数被调用\n"; }
  virtual long GetNumberBelievers() const { return itsNumberBelieves; }

 private:
  long itsNumberBelieves;
};  //多继承

Pegasus::Pegasus(COLOR color, int height, bool migrates, long numberBelieve,
                 int age)
    : Horse(height, color, age),
      Bird(migrates, color, age),
      itsNumberBelieves(numberBelieve),
      Animal(
          age)  //由於使用了虛繼承(虛基類),此時Animal由Pegasus直接構造,所以要顯示調用Animal的構建函數
{
  cout << "Pegasus的构造函数被调用\n";
}

int main() {
  auto_ptr<Pegasus> pPeg(
      new Pegasus(Yellow, 5, true, 10,
                  20));  //使用了智能指針,不需要進行delete,自動調用析構函數.
                         // Pegasus *pPeg = new Pegasus(5, true, 10);
  pPeg->Fly();     //繼承自Bird
  pPeg->Whinny();  //繼承自Horse
  pPeg->Chirp();   //繼承自Bird(被覆蓋)
                  //因爲GetColor()在兩個基類中都有,所以要顯示指明調用的是哪個GetColor()
  COLOR c = pPeg->Horse::GetColor();
  string color;
  switch (c) {
    case Red:
      color = "紅色";
      break;
    case Green:
      color = "綠色";
      break;
    case Blue:
      color = "藍色";
      break;
    case Yellow:
      color = "黃色";
      break;
    case White:
      color = "白色";
      break;
    case Black:
      color = "黑色";
      break;
    case Brown:
      color = "棕色";
      break;
    default:
      color = "未知色";
      break;
  }
  cout << "有" << pPeg->GetNumberBelievers() << "人相信世界上有" << color
       << "的飛馬" << endl;
  /*Pegasus在構建時,由於Horse及Bird繼承自Animal,所以Animal被構建了2此,導致了二義性*/
  cout << pPeg->Horse::GetAge() << endl;

  return 0;
}