#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else { return false; } }
const long long INF = 1LL << 60;
long long dp[110][110000];

int main() {
  int N; 
  long long W;
  cin >> N >> W;
  long long weight[110];
  int value[110];
  for (int i = 0; i < N; i++) {
    cin >> weight[i] >> value[i];
  }

  for (int i = 0; i < 110; i++) {
    if (i == 0) {
      for (int j = 0; j < 110000; j++) {
        dp[i][j] = INF;
      }
    } else {
      dp[i][0] = 0;
    }
  }
  dp[0][0] = 0;

  int maxn = -1;
  for (int i = 1 ; i <= N; i++) {
    for (int j = 0; j < 110000; j++) {
      if (value[i - 1] <= j && dp[i - 1][j - value[i - 1]] != INF) {
        long long x = weight[i - 1] + dp[i - 1][j - value[i - 1]];
        if (x <= W) { 
          maxn = max(maxn, j);
          dp[i][j] = x;
        } else {
          dp[i][j] = INF;
        }
        chmin(dp[i][j], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << maxn << endl;
  return 0;
}
