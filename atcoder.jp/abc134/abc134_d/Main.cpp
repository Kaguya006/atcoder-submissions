#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, n) cin >> a[i + 1];

  vector<int> ball(n + 1);
  for (int i = n; i >= 1; i--) {
    //printf("i = %d\n", i);
    int tmp = i;
    int cnt = 0;
    while (tmp + i <= n) {
      cnt += ball[tmp + i];
      
      tmp += i;
    }

    if (a[i] == 0 && cnt % 2 != 0) {
      ball[i] = 1;
    } else if (a[i] == 1 && cnt % 2 != 1) {
      ball[i] = 1;
    }
  }

  ll sum = accumulate(a.begin(), a.end(), 0);
  if (sum == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (ball[i] == 1) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (auto v : ans) cout << v << " ";
  if (ans.size() != 0) cout << endl;
  
  return 0;
}
