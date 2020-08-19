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
  int N;
  cin >> N;
  vector<int> A(N);
  rep (i, N) cin >> A[i];
  int max = *max_element(A.begin(), A.end());
  vector<int> nums(1e7);
  for (auto v : A) {
    for (int i = 1; v * i <= max; i++) {
      nums[v * i]++;
    }
  }

  int ans = 0;
  for (auto v : A) {
    if (nums[v] != 1) continue;
    ans++;
  }

  cout << ans << endl;
  
  
  return 0;
}
