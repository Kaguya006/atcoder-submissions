#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  int nax = 1005;
  cin >> h >> w;

  vector< char > graph[nax];
  long long dp[nax][nax];
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      graph[i].push_back(s[j]);
    }
  }

  dp[1][1] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (i == 1 && j == 1) continue;
      if (graph[i - 1][j - 1] == '#') continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (long long)(1e9 + 7);
    }
  }
  cout << dp[h][w] << endl;

  return 0;
}
