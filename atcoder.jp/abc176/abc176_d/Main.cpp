#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define all(v) (v).begin(),(v).end()
#define all_rev(v) (v).rbegin(),(v).rend()
#define debug(x) cout << #x << ": " << x << '\n';
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll, ll>;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  //cin.tie(0);ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15);
  int H, W, Ch, Cw, Dh, Dw;
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;

  Ch--; Cw--; Dh--; Dw--;
  P start = {Ch, Cw};
  P goal = {Dh, Dw};

  vector<string> G(H);
  vector<vector<int>> dis(H, vector<int>(W, -1));
  vector<vector<bool>> visited(H, vector<bool>(W));
  rep (i, H) cin >> G[i];

  deque<P> deq;
  deq.push_front(start);

  ll t = 0;
  dis[start.first][start.second] = 0;
  while (!deq.empty()) {
    P current = deq.front();
    if (!visited[current.first][current.second]) {
      visited[current.first][current.second] = true;
      t = dis[current.first][current.second];          
    }

    deq.pop_front();


    
    rep (i, 4) {
      int ny, nx;
      ny = current.first + dy[i];
      nx = current.second + dx[i];

      if (0 <= ny && 0 <= nx && ny < H && nx < W && !visited[ny][nx] && G[ny][nx] == '.') {
        deq.push_front({ny, nx});
	dis[ny][nx] = t;
	visited[ny][nx] = true;
      }
    }
 
    //magic
    int y_range1 = current.first - 2;
    int y_range2 = current.first + 2;
    int x_range1 = current.second - 2;
    int x_range2 = current.second + 2;

    for (int i = y_range1; i <= y_range2; i++) {
      for (int j = x_range1; j <= x_range2; j++) {
	if (0 <= i && 0 <= j && i < H && j < W && !visited[i][j] && dis[i][j] == -1 && G[i][j] == '.') {
	  dis[i][j] = t + 1;
	  deq.push_back({i, j});
	}
      }
    }
  }
  if (visited[goal.first][goal.second]) {
    cout << dis[goal.first][goal.second] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
