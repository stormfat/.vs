#include "workmanger.h"

WorkerManger::WorkerManger() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  // 1.文件不存在
  if (!ifs.is_open()) {
    cout << "文件不存在" << endl;
    this->m_EmpNum = 0;      //初始化人数
    this->m_EmpArray = NULL; //初始化数组指针
    this->m_FileIsEempty = true;
    ifs.close();
    return;
  }

  // 2.文件存在数组为空.
  char ch;
  ifs >> ch; //读走文件流中一个字符
  //如果文件流现在没有字符,就表示上一个读到的字符为文件最后一个字符,表示源文件为空文件.
  if (ifs.eof()) {
    cout << "文件为空" << endl;
    this->m_EmpNum = 0;      //初始化人数
    this->m_EmpArray = NULL; //初始化数组指针
    this->m_FileIsEempty = true;
    ifs.close();
    return;
  }

  // 3.有效文件存在
  int num = this->get_EmpNum();
  cout << "职工人数为: " << num << endl;
  this->m_EmpNum = num;

  this->m_EmpArray = new Worker *[this->m_EmpNum]; //开辟空间
  this->init_Emp(); //将文件的数据,存到数组中
}

void WorkerManger::Show_Menu() {
  cout << "********************************************" << endl;
  cout << "**********  欢迎使用职工管理系统!  *********" << endl;
  cout << "*************  1.增加职工信息  *************" << endl;
  cout << "*************  2.显示职工信息  *************" << endl;
  cout << "*************  3.删除职工信息  *************" << endl;
  cout << "*************  4.修改职工信息  *************" << endl;
  cout << "*************  5.查找职工信息  *************" << endl;
  cout << "*************  6.按照编号排序  *************" << endl;
  cout << "*************  7.清空所有文档  *************" << endl;
  cout << "*************  0.退出管理系统  *************" << endl;
  cout << "********************************************" << endl;
  cout << endl;
}

void WorkerManger::exitSystem() {
  cout << "欢迎下次使用!" << endl;
  system("pause");
  exit(0);
}

void WorkerManger::Add_Emp() {
  cout << "请输入增加职工数量: " << endl;
  int addNum = 0;
  cin >> addNum;
  if (addNum > 0) {
    int newSize = this->m_EmpNum + addNum;     //计算新空间大小
    Worker **newSpace = new Worker *[newSize]; //开辟新空间
    if (this->m_EmpArray != NULL) {
      for (int i = 0; i < this->m_EmpNum; ++i) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    //以下输入新员工信息
    for (int i = 0; i < addNum; ++i) {
      int id;
      string name;
      int dSelect;
      cout << "请输入第 " << i + 1 << " 个新员工编号: " << endl;
      cin >> id;

      cout << "请输入第 " << i + 1 << " 个新员工姓名: " << endl;
      cin >> name;

      cout << "请选择改职工的岗位: " << endl;
      cout << "1.普通职工" << endl;
      cout << "2.经理" << endl;
      cout << "3.老板" << endl;
      cin >> dSelect;

      Worker *worker = NULL;
      switch (dSelect) {
      case 1:
        worker = new Employee(id, name, 1);
        break;
      case 2:
        worker = new Manager(id, name, 2);
        break;
      case 3:
        worker = new Boss(id, name, 3);
        break;
      default:
        break;
      }

      newSpace[this->m_EmpNum + i] = worker; //将新员工加入数组
    }
    delete[] this->m_EmpArray;    //释放原有空间
    this->m_EmpArray = newSpace;  //更改空间指向
    this->m_EmpNum = newSize;     //更新人数
    this->m_FileIsEempty = false; //更新文件存在标志
    cout << "成功添加" << addNum << "名新职工!" << endl;
    //保存数据
    this->save();
  } else {
    cout << "输入有误!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::save() {
  ofstream ofs;
  ofs.open(FILENAME, ios::out); //按文本方式写文件.
  for (int i = 0; i < this->m_EmpNum; i++) {
    ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name
        << " " << this->m_EmpArray[i]->m_DeptId << endl;
  }
  ofs.close();
}

int WorkerManger::get_EmpNum() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int dId;
  int num = 0;
  while (ifs >> id && ifs >> name && ifs >> dId) {
    num++;
  }
  return num;
}

void WorkerManger::init_Emp() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  int id;
  string name;
  int dId;
  int index = 0;
  while (ifs >> id && ifs >> name && ifs >> dId) {
    Worker *worker = NULL;
    if (dId == 1) //普通员工
    {
      worker = new Employee(id, name, dId);
    } else if (dId == 2) //经理
    {
      worker = new Manager(id, name, dId);
    } else {
      worker = new Boss(id, name, dId);
    }
    this->m_EmpArray[index] = worker;
    index++;
  }
  ifs.close();
}

void WorkerManger::Show_Emp() {
  if (this->m_FileIsEempty) {
    cout << "文件不存在或为空" << endl;
  } else {
    for (int i = 0; i < m_EmpNum; i++) {
      //利用多态显示个人信息
      this->m_EmpArray[i]->showInfo();
    }
  }
  system("pause");
  system("cls");
}

// void WorkerManger::Show_Emp(int id) { this->m_EmpArray[id]->showInfo(); }

int WorkerManger::IsExist(int id) {
  int index = -1;
  for (int i = 0; i < this->m_EmpNum; ++i) {
    if (this->m_EmpArray[i]->m_Id == id) {
      index = i;
      break;
    }
  }
  return index;
}

void WorkerManger::Del_Emp() {
  if (this->m_FileIsEempty)
    cout << "文件不存在或记录为空!" << endl;
  else {
    cout << "请输入想要删除职工的编号: " << endl;
    int id = 0;
    cin >> id;
    int index = this->IsExist(id);
    if (index != -1) //职工存在,并且需要将此编号职工删除
    {
      //数据前移
      for (int i = index; i < this->m_EmpNum - 1; i++) {
        this->m_EmpArray[i] = this->m_EmpArray[i + 1];
      }
      this->m_EmpNum--; //更新职工人数
      this->save();     //重写记录文件
      cout << "删除成功!" << endl;
    } else
      cout << "删除失败,未找到职工" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Mod_Emp() {
  if (this->m_FileIsEempty)
    cout << "文件不存在或记录为空!" << endl;
  else {
    cout << "请输入要修改的职工编号: " << endl;
    int id;
    cin >> id;

    int ret = this->IsExist(id);
    if (ret != -1) {
      int newId = 0;
      string newName = "";
      int dSelect = 0;
      cout << "查到: " << id << "号职工,原信息为:\n";
      this->m_EmpArray[ret]->showInfo();
      delete this->m_EmpArray[ret];
      cout << endl;
      cout << "请输入新职工号: " << endl;
      cin >> newId;
      cout << "请输入新姓名:" << endl;
      cin >> newName;
      cout << "请输入岗位: " << endl;
      cout << "1.普通职工" << endl;
      cout << "2.经理" << endl;
      cout << "3.老板" << endl;
      cin >> dSelect;
      Worker *worker = NULL;
      switch (dSelect) {
      case 1:
        worker = new Employee(newId, newName, 1);
        break;
      case 2:
        worker = new Manager(newId, newName, 2);
        break;
      case 3:
        worker = new Boss(newId, newName, 3);
        break;
      default:
        break;
      }
      this->m_EmpArray[ret] = worker;
      cout << "修改成功!" << endl;
      this->save(); //更新记录文件
    } else
      cout << "修改失败,查无此人!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Find_Emp() {
  if (this->m_FileIsEempty)
    cout << "文件不存在或记录为空!" << endl;
  else {
    cout << "请选择1)按职工编号查找,2)按职工姓名查找: ";
    int ch = 0;
    cin >> ch;
    int id;
    int i;
    int ret;
    string name;
    if (ch == 1) {
      cout << "请输入职工编号: ";
      cin >> id;
      ret = this->IsExist(id);
      if (ret != -1)
        this->m_EmpArray[ret]->showInfo();
      else
        cout << "找不到此职工!" << endl;
    } else if (ch == 2) {
      cout << "请输入职工姓名: ";
      cin >> name;
      for (i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Name == name) {
          this->m_EmpArray[i]->showInfo();
          break;
        }
      }
      if (i == this->m_EmpNum)
        cout << "找不到此职工!" << endl;
    } else
      cout << "输入错误!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Sort_Emp() {
  if (this->m_FileIsEempty) {
    cout << "文件不存在或记录为空" << endl;
    system("pause");
    system("cls");
  } else {
    cout << "请选择排序方式: " << endl;
    cout << "1.按职工号进行排序" << endl;
    cout << "2.按职工号进行降序" << endl;
    int select = 0;
    cin >> select;

    for (int i = 0; i < this->m_EmpNum; i++) {
      int minOrMax = i;
      for (int j = 1 + 1; j < this->m_EmpNum; j++) {
        if (select == 1) //升序
        {
          if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
            minOrMax = j; //获取第i轮最小id的下标号
        }

        else {
          if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
            minOrMax = j; //获取第i轮最大id的下标号
        }
        if (i != minOrMax) //当有下标交换时,交换元素
        {
          Worker *temp = m_EmpArray[i];
          m_EmpArray[i] = m_EmpArray[minOrMax];
          m_EmpArray[minOrMax] = temp;
        }
      }
    }
    cout << "排序成功,排序结果为: " << endl;
    this->save();
    this->Show_Emp();
  }
}

void WorkerManger::Clean_File() {
  cout << "确认清空?" << endl;
  cout << "1.确认" << endl;
  cout << "2.返回" << endl;

  int select = 0;
  cin >> select;

  if (select == 1) {
    //打开模式iOS::trunc 如果存在删除文件并重新创建
    ofstream ofs(FILENAME, ios::trunc);
    ofs.close();
    if (this->m_EmpArray != NULL) {
      for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i] != NULL) {
          delete this->m_EmpArray[i];
        }
      }
      this->m_EmpNum = 0;
      delete[] this->m_EmpArray;
      this->m_EmpArray = NULL;
      this->m_FileIsEempty = true;
    }
    cout << "清空成功!" << endl;
  }
  system("pause");
  system("cls");
}

  WorkerManger::~WorkerManger() {
  if (this->m_EmpArray != NULL) {
      for (int i = 0; i < this->m_EmpNum; i++) {
      if (this->m_EmpArray[i] != NULL) {
          delete this->m_EmpArray[i];
        }
    }
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
  }
}