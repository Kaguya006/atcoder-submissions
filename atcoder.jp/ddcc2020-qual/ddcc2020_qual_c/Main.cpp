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
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<int>> graph(300, vector<int>(300));

  int nn = 1;
  rep (i, h) {
    string s;
    cin >> s;
    rep (j, s.size()) {
      if (s[j] == '#') {
	graph[i][j] = nn;
	nn++;
      }    
    }
  }

  int current;
  rep (i, h) {
    current = 0;
    rep (j, w) {
      if (graph[i][j] != 0) current = graph[i][j];
      graph[i][j] = current;
    }

    current = graph[i][w - 1];
    for (int k = w - 1; k >= 0; k--) {
      if (graph[i][k] == 0) graph[i][k] = current;
      else current = graph[i][k];
    }
  }
  
  rep (j, w) {
    current = 0;
    rep (i, h) {
      if (graph[i][j] != 0) current = graph[i][j];
      graph[i][j] = current;
    }

    current = graph[h - 1][j];
    for (int k = h - 1; k >= 0; k--) {
      if (graph[k][j] == 0) graph[k][j] = current;
      else current = graph[k][j];
    }
  }
  
  rep (i, h) {
    rep (j, w) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
