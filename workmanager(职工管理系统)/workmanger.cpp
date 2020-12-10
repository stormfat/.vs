#include "workmanger.h"

WorkerManger::WorkerManger() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);
  // 1.�ļ�������
  if (!ifs.is_open()) {
    cout << "�ļ�������" << endl;
    this->m_EmpNum = 0;      //��ʼ������
    this->m_EmpArray = NULL; //��ʼ������ָ��
    this->m_FileIsEempty = true;
    ifs.close();
    return;
  }

  // 2.�ļ���������Ϊ��.
  char ch;
  ifs >> ch; //�����ļ�����һ���ַ�
  //����ļ�������û���ַ�,�ͱ�ʾ��һ���������ַ�Ϊ�ļ����һ���ַ�,��ʾԴ�ļ�Ϊ���ļ�.
  if (ifs.eof()) {
    cout << "�ļ�Ϊ��" << endl;
    this->m_EmpNum = 0;      //��ʼ������
    this->m_EmpArray = NULL; //��ʼ������ָ��
    this->m_FileIsEempty = true;
    ifs.close();
    return;
  }

  // 3.��Ч�ļ�����
  int num = this->get_EmpNum();
  cout << "ְ������Ϊ: " << num << endl;
  this->m_EmpNum = num;

  this->m_EmpArray = new Worker *[this->m_EmpNum]; //���ٿռ�
  this->init_Emp(); //���ļ�������,�浽������
}

void WorkerManger::Show_Menu() {
  cout << "********************************************" << endl;
  cout << "**********  ��ӭʹ��ְ������ϵͳ!  *********" << endl;
  cout << "*************  1.����ְ����Ϣ  *************" << endl;
  cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
  cout << "*************  3.ɾ��ְ����Ϣ  *************" << endl;
  cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
  cout << "*************  5.����ְ����Ϣ  *************" << endl;
  cout << "*************  6.���ձ������  *************" << endl;
  cout << "*************  7.��������ĵ�  *************" << endl;
  cout << "*************  0.�˳�����ϵͳ  *************" << endl;
  cout << "********************************************" << endl;
  cout << endl;
}

void WorkerManger::exitSystem() {
  cout << "��ӭ�´�ʹ��!" << endl;
  system("pause");
  exit(0);
}

void WorkerManger::Add_Emp() {
  cout << "����������ְ������: " << endl;
  int addNum = 0;
  cin >> addNum;
  if (addNum > 0) {
    int newSize = this->m_EmpNum + addNum;     //�����¿ռ��С
    Worker **newSpace = new Worker *[newSize]; //�����¿ռ�
    if (this->m_EmpArray != NULL) {
      for (int i = 0; i < this->m_EmpNum; ++i) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    //����������Ա����Ϣ
    for (int i = 0; i < addNum; ++i) {
      int id;
      string name;
      int dSelect;
      cout << "������� " << i + 1 << " ����Ա�����: " << endl;
      cin >> id;

      cout << "������� " << i + 1 << " ����Ա������: " << endl;
      cin >> name;

      cout << "��ѡ���ְ���ĸ�λ: " << endl;
      cout << "1.��ְͨ��" << endl;
      cout << "2.����" << endl;
      cout << "3.�ϰ�" << endl;
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

      newSpace[this->m_EmpNum + i] = worker; //����Ա����������
    }
    delete[] this->m_EmpArray;    //�ͷ�ԭ�пռ�
    this->m_EmpArray = newSpace;  //���Ŀռ�ָ��
    this->m_EmpNum = newSize;     //��������
    this->m_FileIsEempty = false; //�����ļ����ڱ�־
    cout << "�ɹ����" << addNum << "����ְ��!" << endl;
    //��������
    this->save();
  } else {
    cout << "��������!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::save() {
  ofstream ofs;
  ofs.open(FILENAME, ios::out); //���ı���ʽд�ļ�.
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
    if (dId == 1) //��ͨԱ��
    {
      worker = new Employee(id, name, dId);
    } else if (dId == 2) //����
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
    cout << "�ļ������ڻ�Ϊ��" << endl;
  } else {
    for (int i = 0; i < m_EmpNum; i++) {
      //���ö�̬��ʾ������Ϣ
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
    cout << "�ļ������ڻ��¼Ϊ��!" << endl;
  else {
    cout << "��������Ҫɾ��ְ���ı��: " << endl;
    int id = 0;
    cin >> id;
    int index = this->IsExist(id);
    if (index != -1) //ְ������,������Ҫ���˱��ְ��ɾ��
    {
      //����ǰ��
      for (int i = index; i < this->m_EmpNum - 1; i++) {
        this->m_EmpArray[i] = this->m_EmpArray[i + 1];
      }
      this->m_EmpNum--; //����ְ������
      this->save();     //��д��¼�ļ�
      cout << "ɾ���ɹ�!" << endl;
    } else
      cout << "ɾ��ʧ��,δ�ҵ�ְ��" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Mod_Emp() {
  if (this->m_FileIsEempty)
    cout << "�ļ������ڻ��¼Ϊ��!" << endl;
  else {
    cout << "������Ҫ�޸ĵ�ְ�����: " << endl;
    int id;
    cin >> id;

    int ret = this->IsExist(id);
    if (ret != -1) {
      int newId = 0;
      string newName = "";
      int dSelect = 0;
      cout << "�鵽: " << id << "��ְ��,ԭ��ϢΪ:\n";
      this->m_EmpArray[ret]->showInfo();
      delete this->m_EmpArray[ret];
      cout << endl;
      cout << "��������ְ����: " << endl;
      cin >> newId;
      cout << "������������:" << endl;
      cin >> newName;
      cout << "�������λ: " << endl;
      cout << "1.��ְͨ��" << endl;
      cout << "2.����" << endl;
      cout << "3.�ϰ�" << endl;
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
      cout << "�޸ĳɹ�!" << endl;
      this->save(); //���¼�¼�ļ�
    } else
      cout << "�޸�ʧ��,���޴���!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Find_Emp() {
  if (this->m_FileIsEempty)
    cout << "�ļ������ڻ��¼Ϊ��!" << endl;
  else {
    cout << "��ѡ��1)��ְ����Ų���,2)��ְ����������: ";
    int ch = 0;
    cin >> ch;
    int id;
    int i;
    int ret;
    string name;
    if (ch == 1) {
      cout << "������ְ�����: ";
      cin >> id;
      ret = this->IsExist(id);
      if (ret != -1)
        this->m_EmpArray[ret]->showInfo();
      else
        cout << "�Ҳ�����ְ��!" << endl;
    } else if (ch == 2) {
      cout << "������ְ������: ";
      cin >> name;
      for (i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Name == name) {
          this->m_EmpArray[i]->showInfo();
          break;
        }
      }
      if (i == this->m_EmpNum)
        cout << "�Ҳ�����ְ��!" << endl;
    } else
      cout << "�������!" << endl;
  }
  system("pause");
  system("cls");
}

void WorkerManger::Sort_Emp() {
  if (this->m_FileIsEempty) {
    cout << "�ļ������ڻ��¼Ϊ��" << endl;
    system("pause");
    system("cls");
  } else {
    cout << "��ѡ������ʽ: " << endl;
    cout << "1.��ְ���Ž�������" << endl;
    cout << "2.��ְ���Ž��н���" << endl;
    int select = 0;
    cin >> select;

    for (int i = 0; i < this->m_EmpNum; i++) {
      int minOrMax = i;
      for (int j = 1 + 1; j < this->m_EmpNum; j++) {
        if (select == 1) //����
        {
          if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
            minOrMax = j; //��ȡ��i����Сid���±��
        }

        else {
          if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
            minOrMax = j; //��ȡ��i�����id���±��
        }
        if (i != minOrMax) //�����±꽻��ʱ,����Ԫ��
        {
          Worker *temp = m_EmpArray[i];
          m_EmpArray[i] = m_EmpArray[minOrMax];
          m_EmpArray[minOrMax] = temp;
        }
      }
    }
    cout << "����ɹ�,������Ϊ: " << endl;
    this->save();
    this->Show_Emp();
  }
}

void WorkerManger::Clean_File() {
  cout << "ȷ�����?" << endl;
  cout << "1.ȷ��" << endl;
  cout << "2.����" << endl;

  int select = 0;
  cin >> select;

  if (select == 1) {
    //��ģʽiOS::trunc �������ɾ���ļ������´���
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
    cout << "��ճɹ�!" << endl;
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