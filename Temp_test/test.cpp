#include <stdlib.h>

#include <iostream>
using namespace std;

struct LinkstNode {
  int data;
  LinkstNode *next;
};

void InitStack(LinkstNode *&s) {
  s = (LinkstNode *)malloc(sizeof(LinkstNode));
  s->next = NULL;
}

void Push(LinkstNode *&s, int a[], int n) {
  LinkstNode *r;
  s = (LinkstNode *)malloc(sizeof(LinkstNode));
  s->next = NULL;
  for (int i = 0; i < n; i++) {
    r = (LinkstNode *)malloc(sizeof(LinkstNode));
    r->data = a[i];
    r->next = s->next;
    s->next = r;
  }
}
void Push(LinkstNode *&s, int e) {
  LinkstNode *r;
  s = (LinkstNode *)malloc(sizeof(LinkstNode));
  s->next = NULL;
  r = (LinkstNode *)malloc(sizeof(LinkstNode));
  r->data = e;
  r->next = s->next;
  s->next = r;
}

void Locate(LinkstNode *&s, int e) {
  LinkstNode *l;
  s = (LinkstNode *)malloc(sizeof(LinkstNode));
  s->next = NULL;
  l = (LinkstNode *)malloc(sizeof(LinkstNode));
  l->data = e;
  l->next = s->next;
  s->next = l;
}

void DispStack(LinkstNode *s, int n) {
  int *a;
  a = new int[n];
  
  for (int i = 0; i < n; i++) {
    a[i] = s->next->data;
    s = s->next;
  }
  cout << "出栈的顺序" << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

bool pop(LinkstNode *s, int &e) {
  LinkstNode *p;
  if (s->next == NULL) return false;
  p = s->next;
  e = p->data;
  s->next = p->next;
  free(p);
  return true;
}
int gettop(LinkstNode *s) {
  LinkstNode *p;
  int e;
  if (s->next == NULL) return false;
  e = s->next->data;
  return e;
}

void paixu(LinkstNode *s) {
  LinkstNode *m;
  InitStack(m);
  int temp1;
  int temp2;
  pop(s, temp1);
  cout << "取出s栈中的元素:" << temp1 << "放入m栈中" << endl;
  Push(m, temp1);
  while (s->next != NULL) {
    pop(s, temp1);
    cout << "取出s栈中的元素:" << temp1 << endl;
    if (temp1 > gettop(m)) {
      cout << "因为" << temp1 << ">" << gettop(m) << "所以将" << temp1
           << "放入m栈" << endl;
      Locate(m, temp1);
      cout << "取出m的第一个元素：" << gettop(m) << endl;
    }
    if (temp1 < gettop(m)) {
      pop(m, temp2);
      cout << "因为" << temp1 << "<" << temp2 << "所以将" << temp2 << "取出"
           << endl;
      Locate(s, temp2);
      cout << "将" << s->next->data << "放回s栈" << endl;
      Locate(m, temp1);
      cout << "再将" << m->next->data << "放入m栈" << endl;
    }
  }
}

int main() {
  int a[4] = {2, 4, 5, 1};
  int n = 4;
  LinkstNode *s;
  InitStack(s);
  Push(s, a, n);
  DispStack(s, a[4]);
  paixu(s);
  return 0;
}