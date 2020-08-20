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
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep (i, N) A[i] = i;
  vector<P> mp(N);
  rep (i, N) {
    int x, y;
    cin >> x >> y;
    mp[i] = make_pair(x, y);
  }

  double sum = 0;
  int cnt = 0;
  do {
    P current = mp[A[0]];
    for (int i = 1; i < N; i++) {
      int dx = abs(current.first - mp[A[i]].first);
      int dy = abs(current.second - mp[A[i]].second);
      sum += sqrt(dx*dx + dy*dy);
      current = mp[A[i]];
    }
    cnt++;
  } while (next_permutation(A.begin(), A.end()));
  cout << fixed << setprecision(15) << sum / cnt << endl;
  return 0;
}
