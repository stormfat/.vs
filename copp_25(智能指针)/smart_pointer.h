#pragma once
template <typename T>
class smart_pointer {
 public:
  smart_pointer(T*pData):m_pRawPointer(pData) {}
  //复制构造函数
  smart_pointer(const smart_pointer &anothersp) {}
  //赋值函数
  smart_pointer& operator=(const smart_pointer& anothersp);
  //重载*操作符
  T& operator*() const { return *(m_pRawPointer); }
  //重载->操作符
  T& operator->() const { return m_pRawPointer; }
 private:
  T* m_pRawPointer;
};