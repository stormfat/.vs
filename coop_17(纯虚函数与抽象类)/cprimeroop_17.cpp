#include <iostream>
#include <string>
using namespace std;

//包含纯虚函数的类为抽象类,抽象类用来继承不能实例化,派生类要覆盖从这个类继承的纯虚函数,如果派生类没有覆盖基类的纯虚函数则也成为一个抽象类.
class Shape {
 public:
  Shape() {}
  virtual ~Shape() {}
  virtual double GetArea() = 0;  //纯虚函数
  virtual double GetPerim() = 0;
  virtual void Draw() = 0;
};

class Circle : public Shape {
 public:
  Circle(int radius) : itsRadius(radius) {}
  virtual ~Circle() {}  //类里有虚函数的话,建议虚构函数写成虚函数.
  double GetArea() {
    return 3.14 * itsRadius * itsRadius;
  }  //虽然被覆写了,但依旧是虚函数
  double GetPerim() { return 2 * 3.14 * itsRadius; }
  void Draw();

 private:
  int itsRadius;
};

void Circle::Draw() { cout << "Circle drawing routing here!\n"; }

class Rectangle : public Shape {
 public:
  Rectangle(int len, int width) : itsLength(len), itsWidth(width) {}
  virtual ~Rectangle() {}
  double GetArea() { return itsLength * itsWidth; }
  double GetPerim() { return 2 * itsLength * itsWidth; }
  virtual int GetLength() { return itsLength; }
  virtual int GetWidth() { return itsWidth; }
  void Draw();

 private:
  int itsWidth;
  int itsLength;
};

void Rectangle::Draw() {
  for (int i = 0; i < itsLength; i++) {
    for (int j = 0; j < itsWidth; j++) cout << "x ";
    cout << "\n";
  }
}

class Square : public Rectangle {
 public:
  Square(int len);
  Square(int len, int width);
  virtual ~Square(){};
  double GetPerim() { return 4 * GetLength(); }
  double GetArea() { return GetLength() * GetLength(); }
};

Square::Square(int len) : Rectangle(len, len) {}
Square::Square(int len, int width) : Rectangle(len, width) {
  if (GetLength() != GetWidth()) cout << "error not a Square!\n";
}

int main() {
  int choice;
  Shape *sp = nullptr;
  bool fQuit = false;
  while (fQuit == false) {
    cout << "(1)Circle (2)Rectangle (3)Square (0)Quit:";
    cin >> choice;
    switch (choice) {
      case 1:
        sp = new Circle(5);
        break;
      case 2:
        sp = new Rectangle(4, 6);
        break;
      case 3:
        sp = new Square(5);
        break;
      case 0:
        fQuit = true;
        break;
      default:
        break;
    }
    if (nullptr!=sp) {
      sp->Draw();
      delete sp;
      cout << endl;
    }
  }
  return 0;
}