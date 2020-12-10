#pragma warning(disable : 4786)
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  wstring ws1, ws2;

  wcin.imbue(locale("chs"));
  wcout.imbue(locale("chs"));
  getline(wcin, ws1);
  getline(wcin, ws2);
  if (ws1.size() != ws2.size()) {
    wcout << ws1 << L" 和 " << ws2 << L" 不对应" << endl;
    return 1;
  }

  map<wchar_t, wchar_t> m1, m2;
  int n = ws1.size();

  for (int i = 0; i < n; i++) {
    if (m1.find(ws1[i]) == m1.end() && m2.find(ws2[i]) == m2.end()) {
      m1[ws1[i]] = ws2[i];
      m2[ws2[i]] = ws1[i];
    } else {
      if (m1[ws1[i]] != ws2[i] || m2[ws2[i]] != ws1[i]) {
        wcout << ws1 << L" 和 " << ws2 << L" 不对应" << endl;
        return 1;
      }
    }
  }
  wcout << ws1 << L" 和 " << ws2 << L" 对应" << endl;
  return 0;
}
