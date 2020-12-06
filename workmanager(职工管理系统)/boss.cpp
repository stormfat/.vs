#include "boss.h"

Boss::Boss(int id, string name, int dId) {
  this->m_Id = id;
  this->m_DeptId = dId;
  this->m_Name = name;
}

void Boss::showInfo() {
  cout << "职工编号: " << this->m_Id << "\t职工姓名: " << this->m_Name
       << "\t岗位: " << this->getDeptName() << "\t岗位职责:管理公司所有事务"
       << endl;
}

string Boss::getDeptName() { return string("总裁"); }