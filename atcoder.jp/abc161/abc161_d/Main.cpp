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
  int k;
  cin >> k;
  queue<ll> qi;
  rep (i, 9) qi.push(i + 1);

  int cnt = 1;
  ll x = 0;
  while (true) {
    x = qi.front();
    qi.pop();

    if (cnt == k) break;

    if (x % 10 != 0) {
      qi.push(10 * x + x % 10 - 1);
    }
    qi.push(10 * x + x % 10);
    if (x % 10 != 9) {
      qi.push(10 * x + x % 10 + 1);
    }
    ++cnt;
  }

  cout << x << endl;

  return 0;
}
