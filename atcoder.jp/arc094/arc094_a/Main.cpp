#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << '\n';
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
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> T;
  T.push_back(A);
  T.push_back(B);
  T.push_back(C);
  sort(T.rbegin(), T.rend());
  A = T[0];
  B = T[1];
  C = T[2];

  ll ans = 0;
  while(A != B) {
    B++;
    C++;
    ans++;
  }

  ans += (A - C) / 2;
  if ((A - C) % 2 == 1) ans += 2;

  cout << ans << endl;
  
  return 0;
}
