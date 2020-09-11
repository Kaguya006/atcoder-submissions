#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;

int main() {
  int N;
  cin >> N;
  ll maxn = 1e6 + 10;
  vector<int> A(N);
  vector<int> used(maxn);
  rep (i, N) {
    cin >>  A[i];
    used[A[i]]++;
  }

  bool ck1 = true;
  for (ll i = 2; i < maxn; i++) {
    int cnt = 0;
    for (ll j = 1; i * j < maxn; j++) {
      cnt += used[i * j];
      if (cnt > 1) {
	ck1 = false;
	break;
      }
    }
  }

  bool ck2 = false;
  int x = gcd(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    x = gcd(x, A[i]);
    if (x == 1) ck2 = true;
  }

  if (ck1) {
    cout << "pairwise coprime" << endl;
  } else if (ck2) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }

  
  return 0;
}
