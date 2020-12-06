#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
  virtual void showInfo() = 0;      //显示个人信息
  virtual string getDeptName() = 0; //获取岗位名称

  int m_Id;      //编号
  string m_Name; //姓名
  int m_DeptId;  //部门编号
};
