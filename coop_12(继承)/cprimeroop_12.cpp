/*class B:public A 公有继承(基类中public/protected成员被继承,且不改变访问属性,可多代继承)--接口继承(使用较多)
  class B:private A 私有继承(基类中public/protected成员被继承,且都改为private访问属性,只可继承一代)
  class B:protected A 受保护继承(基类中public/protected成员被继承,且public成员改为protected访问属性
  默认继承方式为private*/

#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A()
    {
        a = 10;
        b = 20;
        c = 30;
    }
    int a;

public:
    void set_b(int c) { b = c; }
    int get_b() { return b; }
    int get_a() { return a; }

protected:
    int b; //protected成员在公有继承的模式下可以被多代继承.不改变基类成员的访问类型

private:
    int c;
    int get_c() { return c; }
};

class B1 : public A {
};

class C : public B1 {
};

class B2 : private A {
public:
    using A::a; //将已变成private的a通过using转为相应访问属性.除去个别成员.
};

class C1 : public B2 {
    //由于B2是私有继承自A,所有A中public/protected成员变成private成员,不可再次继承.C1不可使用B2.a,B2.b,B2.c
};

int main()
{
    A a;
    B1 b1;
    C c;
    C1 c1;
    b1.set_b(4);
    c.set_b(5);
    cout << "b1中的b成员:\t" << b1.get_b() << endl; //继承基类的protected成员不能用b1.b的方式直接调用.
    cout << "c中的b成员:\t" << c.get_b() << endl;
    cout << "B2中继承自A的a可以被c1访问:\t" << c1.a << endl;

        return 0;
}