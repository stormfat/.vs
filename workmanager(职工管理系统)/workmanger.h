#pragma once //防止头文件被重复包含
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include <fstream>
#include <iostream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManger {
public:
  WorkerManger();
  void Show_Menu();
  void exitSystem();
  void Add_Emp(); //增加员工
  void save();    //保存文件
  bool m_FileIsEempty;
  int get_EmpNum(); //统计文件中的人数
  void init_Emp();  //初始化员工
  void Show_Emp();
  void Del_Emp();
  int IsExist(int id);
  void Mod_Emp();
  //void Show_Emp(int id);
  void Find_Emp();
  void Sort_Emp();
  void Clean_File();
  
  ~WorkerManger();

  int m_EmpNum;        //记录文件中的人数个数
  Worker **m_EmpArray; //员工数组的指针
};
