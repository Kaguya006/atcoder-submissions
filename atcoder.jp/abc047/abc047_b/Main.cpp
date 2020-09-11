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
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> width(110);
  vector<int> height(110);
  for (int i = 0; i <= W; i++) width[i] = 1;
  for (int i = 0; i <= H; i++) height[i] = 1;
  
  rep (i, N) {
    int x, y, a;
    cin >> x >> y >> a;

    if (a == 1) {
      for (int i = 0; i < x; i++) width[i] = 0;
    }

    if (a == 2) {
      for (int i = x + 1; i <= 100; i++) width[i] = 0;
    }

    if (a == 3) {
      for (int i = 0; i < y; i++) height[i] = 0;
    }

    if (a == 4) {
      for (int i = y + 1; i <= 100; i++) height[i] = 0;
    }
  }

  int w = 0, h = 0;
  rep (i, 110) if (width[i] == 1) w++;
  rep (i, 110) if (height[i] == 1) h++;

  //cout << w - 1 << " " << h - 1<< endl;
  if ((w - 1) >= 0 && (h - 1) >= 0) {
    cout << (w - 1) * (h - 1) << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
