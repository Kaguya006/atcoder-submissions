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
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  int right = 0;
  ll res = 0;
  ll sum = 0;
  for (int left = 0; left < n; left++) {
    while (right < n && sum + a[right] < k) {
      sum += a[right];
      ++right;
    }
    //printf("%d - %d = %d | sum = %d\n", n, right, n - right, sum);
    res += n - right;

    if (left == right) ++right;
    else sum -= a[left];
  }

  cout << res << endl;
  return 0;
}
