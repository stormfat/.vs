#include "manager.h"

Manager::Manager(int id, string name, int dId) {
  this->m_Id = id;
  this->m_DeptId = dId;
  this->m_Name = name;
}

void Manager::showInfo() {
  cout << "ְ�����: " << this->m_Id << "\tְ������: " << this->m_Name
       << "\t��λ: " << this->getDeptName()
       << "\t��λְ��:����ϰ彻������,���·������Ա��" << endl;
}

string Manager::getDeptName() { return string("����"); }