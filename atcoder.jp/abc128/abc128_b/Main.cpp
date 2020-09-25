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
  int n; cin >> n;
  map<string, vector<pair<int, int>>> rank;
  set<string> cities;
  rep (i, n) {
    string s;
    int p;
    cin >> s >> p;
    rank[s].push_back(make_pair(p, i));
    cities.insert(s);
  }

  for (auto v : cities) {
    sort(rank[v].rbegin(), rank[v].rend());
    for (auto vv : rank[v]) {
      cout << vv.second + 1 << endl;
    }
  }
  return 0;
}
