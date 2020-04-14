#include <bits/stdc++.h>
using namespace std;

int main() {
  bool flg = false;
  string s;
  cin >> s;

  for (int i = 0; i < 3; i++) if (s[i] == '7') flg = true;
  if (flg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
