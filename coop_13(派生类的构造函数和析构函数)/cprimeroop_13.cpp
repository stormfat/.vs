/*类的继承不包括基类的构造函数和析构函数,所以在设计派生类构造函数的时候要调用基类构造函数.
  构造函数执行顺序:
  基类构造函数->成员对象构造函数->派生类构造函数
  */

#include <iostream>
#include <string>
using namespace std;

class Father {
};

class Son : public Father {
};

class Base1 {
public:
    Base1(int i)
        : b1(i)
    {
        cout << "Base1的构造函数被调用!" << endl;
    }

    void Print() const { cout << b1 << endl; }

private:
    int b1;
};

class Base2 {
public:
    Base2(int i)
        : b2(i)
    {
        cout << "Base2的构造函数被调用!" << endl;
    }
    void Print() const
    {
        cout << b2 << endl;
    }

private:
    int b2;
};

class Base3 {
public:
    Base3()
        : b3(0)
    {
        cout << "Base3缺省的构造函数被调用!" << endl;
    }
    void Print() const
    {
        cout << b3 << endl;
    }

private:
    int b3;
};

class Member {
public:
    Member(int i)
        : m(i)
    {
        cout << "Member的构造函数被调用" << endl;
    }
    int get_m() { return m; }

private:
    int m;
};

class Derived : public Base2, public Base1, public Base3 {//在类声明中决定了基类构造函数的调用顺序.
public:
    Derived(int i, int j, int k, int l);
    void Print();
private:
    int d;
    Member mem;//成员对象也先与类构造.
};
Derived::Derived(int i, int j, int k, int l)
    : Base1(i)
    , Base2(j)
    , mem(k)
    , d(l)
{
    cout << "Derived的构造函数被调用!" << endl;
}

void Derived::Print()
{
    Base1::Print();
    Base2::Print();
    Base3::Print();
    cout << mem.get_m() << endl;
    cout << d << endl;
}

int main()
{
    Son a; //派生类创建对象时需要先创建基类,这样才能使用基类的成员.
    Derived obj(1, 2, 3, 4);
    obj.Print();
    return 0;
}