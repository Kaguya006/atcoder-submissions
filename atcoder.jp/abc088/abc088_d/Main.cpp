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
  int H, W;
  cin >> H >> W;
  vector<string> G(H);

  ll black = 0;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    G[i] = s;
    for (auto v : s) if (v == '#') black++;
  }


  vector<vector<int>> visited(H, vector<int>(W));
  vector<vector<int>> dis(H, vector<int>(W));
  queue<P> que;
  que.push({0, 0});
  visited[0][0] = 1;
  while (!(que.empty())) {
    P current = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int new_y = current.second + dy[i];
      int new_x = current.first + dx[i];
      if (0 <= new_y && 0 <= new_x && new_y < H && new_x < W) {
	if (visited[new_y][new_x]  == 0 && G[new_y][new_x] == '.') {
	  que.push({new_x, new_y});
	  visited[new_y][new_x] = 1;
	  dis[new_y][new_x] = dis[current.second][current.first] + 1;
	}
      }
    }
  }

  if (visited[H - 1][W - 1]) {
    cout << ((H * W) - (dis[H - 1][W - 1] + 1)) - black << endl;
  } else {
    cout << -1 << endl;
  }

  
  
  return 0;
}
