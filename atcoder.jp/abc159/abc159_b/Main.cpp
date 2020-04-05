#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  //akasaka
  int n = s.size();
  string a, b;
  for (int i = 0; i < (n - 1) / 2; i++) a += s[i];
  b = a;
  reverse(a.begin(), a.end());
  if (a == b) {
    for (int i = (n + 3) / 2; i < n; i++) a += s[i];
    b = a;
    reverse(a.begin(), a.end());
    if (a == b) { 
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}
