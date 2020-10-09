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
  int H, W, K;
  cin >> H  >> W >> K;
  vector<vector<char>> G(H);

  int blacks = 0;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    for (auto v : s) {
      if (v == '#') blacks++;
      G[i].push_back(v);
    }
  }

  int ans = 0;
  int cnt;
  for (int bit = 0; bit < (1 << H); bit++) {
    vector<vector<char>> g = G;
    cnt = 0;
    for (int i = 0; i < H; i++) {
      if (bit & (1 << i)) {
	for (int j = 0; j < W; j++) {
	  if (g[i][j] == '#') {
	    cnt++;
	    g[i][j] = '.';
	  }
	}
      }
    }

    for (int bit2 = 0; bit2 < (1 << W); bit2++) {
      vector<vector<char>> gg = g;
      int cnt2 = cnt;      
      for (int j = 0; j < W; j++) {
	if (bit2 & (1 << j)) {
	  for (int i = 0; i < H; i++) {
	    if (gg[i][j] == '#') cnt2++;
	  }	
	}
      }
      if ((blacks - cnt2) ==  K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
