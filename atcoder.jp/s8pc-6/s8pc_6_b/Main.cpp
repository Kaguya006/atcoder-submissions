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
  vector<int> B(N);
  rep (i, N) cin >> A[i] >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int a_mid, b_mid;
  if (N & 1) {
    a_mid = A[N / 2];
    b_mid = B[N / 2];
  } else {
    a_mid = A[N / 2 - 1];
    b_mid = B[N / 2 - 1];
  }

  ll ans = 0;
  rep (i, N) {
    ans += abs(A[i] - B[i]);
    ans += abs(A[i] - a_mid);
    ans += abs(B[i] - b_mid);
  }

  cout << ans << endl;
  return 0;
}
