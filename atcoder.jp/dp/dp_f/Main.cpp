#include <bits/stdc++.h>
using namespace std;

int dp[3010][3010];
int main() {
  string S,T;
  cin >> S;
  cin >> T;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < T.size(); j++) {
      if (S[i] == T[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
    }
  }
  string str = "";
  int i = S.size();
  int j = T.size();
  while (0 < i && 0 < j) {
    int x = dp[i][j];
    if (dp[i - 1][j] == x) {
      i--;
    } else if (dp[i][j -1] == x) {
      j--;
    } else {
      str = S[i - 1] + str;
      i--;
      j--;
    }
  }
  cout << str << endl;
  return 0;
}
