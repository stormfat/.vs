#include "workmanger.h"
//#include "worker.h"
//#include "employee.h"
#include <iostream>
using namespace std;

int main() {
  //实例化管理者对象
  WorkerManger wm;

  int choice = 0;
  while (true) {
    //调用展示菜单成员函数
    wm.Show_Menu();
    cout << "请输入你的选择:" << endl;
    cin >> choice;
    switch (choice) {
    case 0: //退
      wm.exitSystem();
      break;
    case 1: //增
      wm.Add_Emp();
      break;
    case 2: //显
      wm.Show_Emp();
      break;
    case 3: //删
      wm.Del_Emp();
      break;
    case 4: //改
      wm.Mod_Emp();
      break;
    case 5: //查
      wm.Find_Emp();
      break;
    case 6: //排
      wm.Sort_Emp();
      break;
    case 7: //清
      wm.Clean_File();
      break;
    default:
      system("cls"); //清屏
      break;
    }
  }

  system("pause");
  return 0;
}