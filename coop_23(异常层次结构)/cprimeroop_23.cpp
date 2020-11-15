/*学习目的:
创建自己的异常类
异常派生类
异常中的数据:数据成员
按引用传递异常 -|
              ->在异常中使用虚函数*/

#include <iostream>
#include <string>
using namespace std;

const int DefaultSize = 10;
//动态数组
class Array {
 public:
  Array(int itsSize = DefaultSize);
  ~Array() { delete[] pType; }
  //访问器
  int GetitSize() const { return itsSize; }
  //操作符重载
  int& operator[](int offSet);
  const int& operator[](int offSet) const;
  //异常类
  class xBoundary {
   public:
    xBoundary() { cout << "下标越界" << endl; }
  };
  class xSize {
   public:
    xSize() {}
    xSize(int size):itsSize(size) {}
    ~xSize() {}
    int GetSize() { return itsSize; }
    virtual void PrintError() { cout << "下标发生错误:" << itsSize << endl; }
   private:
    int itsSize;
  };
  class xZero : public xSize {
   public:
    xZero() {}
    xZero(int size) : xSize(size) { cout <<"数组个数是:"<< GetSize() <<endl; }
    void PrintError() { cout << "下标不能是0!" << endl; }
  };
  class xTooSmall : public xSize {
   public:
    xTooSmall() {}
    xTooSmall(int size) : xSize(size) {
      cout << "数组个数是" << GetSize() << ",个数太小,需要在0~10之间" << endl;
    }
    void PrintError() { cout << "数组个数太小" << endl; }
  };
  class xTooBig :public xSize{};
  class xNegative :public xSize{
   public:
    xNegative() { cout << "数组个数不能小于0" << endl; }
  };

 private:
  int* pType;
  int itsSize;
};

Array::Array(int size) : itsSize(size) {
  //建立动态数组前对初始化数组的参数进行合法性检查
  if (size == 0) throw xZero(size);
  if (size > 0 && size < 10) throw xTooSmall(size);//要在0~10之间
  if (size > 30000) throw xTooBig();
  if (size < 0) throw xNegative();

  pType = new int[size];  //动态创建数组
  for (int i = 0; i < size; i++) pType[i] = 0;
}

int& Array::operator[](int offSet) {
  int size = this->GetitSize();
  if (offSet >= 0 && offSet < size) return pType[offSet];
  throw xBoundary();
}

const int& Array::operator[](int offSet) const {
  int size = this->GetitSize();
  if (offSet >= 0 && offSet < size) return pType[offSet];
  throw xBoundary();
}

int main() {
  Array a;
  Array b(12);
  Array intArray(20);

  try {
    Array c(0);
    /* b[8] = 7;
     b[22] = 99;
     cout << b[6] << endl;*/
    for (int j = 0; j < 100; j++) {
      intArray[j] = j;
      cout << "intArray[" << j << "] okay..." << endl;
    }
  } catch (Array::xSize& exp) {//基类多态的应用.
    exp.PrintError();
  }
  /*catch (Array::xTooSmall e) {
    e.PrintError();
  } 
  catch (Array::xZero e) {
    e;
  } catch (Array::xBoundary e) {
    e;
  } catch (Array::xNegative e) {
    e;
  }*/

  cout << "OK" << endl;
  return 0;
}