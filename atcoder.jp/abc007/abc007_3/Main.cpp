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
  int r, c;
  cin >> r >> c;
  vector<vector<char>>G(1010, vector<char>(1010));
  vector<vector<int>>D(1010, vector<int>(1010));
  vector<vector<bool>>visited(1010, vector<bool>(1010));
  int sy, sx, gy, gx;
  cin >> sy >> sx;
  cin >> gy >> gx;
  --sy;--sx;--gy;--gx;

  rep (i, r) {
    string s;
    cin >> s;
    rep (j, s.size()) {
      G[i][j] = s[j];
    }
  }

  //bfs
  queue<P> qi;
  qi.push(make_pair(sy, sx));
  visited[sy][sx] = true;

  int py[] = {1, -1, 0, 0};
  int px[] = {0, 0, 1, -1};
  while (!qi.empty()) {
    int now_y = qi.front().first;
    int now_x = qi.front().second;
    qi.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = now_y + py[i];
      int next_x = now_x + px[i];
      if (0 <= next_y && 0 <= next_x)
        if (r > next_y && c > next_x)
	  if (!visited[next_y][next_x] && G[next_y][next_x] == '.') {
	    visited[next_y][next_x] = true;
	    qi.push(make_pair(next_y, next_x));
	    D[next_y][next_x] = D[now_y][now_x] + 1;
	  }
    }
  }

  cout << D[gy][gx] << endl;
	  
  return 0;
}
