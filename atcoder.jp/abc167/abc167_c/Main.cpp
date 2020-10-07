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
  int N, M, X;
  cin >> N >> M >> X;

  vector<vector<int>> A(N, vector<int>(M));
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  vector<int> ans;
  for (int bit = 1; bit < (1 << N); bit++) {
    vector<int> counter(M);
    int price = 0;
    for (int j = 0; j < N; j++) {
      if (bit & 1 << j) {
	price += C[j];	
	for (int k = 0; k < M; k++) {
	  counter[k] += A[j][k];
	}
      }
    }

    bool ok = true;
    for (auto v : counter) {
      if (v < X) ok = false;
    }
    if (ok) ans.push_back(price);
  }

  if (ans.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  
  sort(ALL(ans));
  cout << ans[0] << endl;
  return 0;
}
