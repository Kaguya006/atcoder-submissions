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
  int N, ng1, ng2, ng3;
  cin >> N >> ng1 >> ng2 >> ng3;

  int n = N;
  int cnt = 0;
  bool ok = true;
  while (ok && n > 0) {
    int tmp3 = n - 3;
    int tmp2 = n - 2;
    int tmp1 = n - 1;
    if (tmp3 == ng1 || tmp3 == ng2 || tmp3 == ng3) {
      if (tmp2 == ng1 || tmp2 == ng2 || tmp2 == ng3) {
	if (tmp1 == ng1 || tmp1 == ng2 || tmp1 == ng3) {
	  ok = false;
	} else {
	  n -= 1;
	}
      } else {
	n -= 2;
      }
    } else {
      n -= 3;
    }
    cnt++;
  }

  //exception
  if (N == ng1 || N == ng2 || N == ng3) ok = false;

  if (ok && cnt <= 100 && n <= 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
