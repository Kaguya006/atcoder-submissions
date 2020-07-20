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
  int n, h;
  cin >> n >> h;
  vector<pair<ll, ll>> attack;
  rep (i, n) {
    int a, b;
    cin >> a >> b;
    attack.push_back(make_pair(a, 1));
    attack.push_back(make_pair(b, 0));
  }

  sort(attack.rbegin(), attack.rend());

  int ans = 0;
  for (auto v : attack) {
    bool finish = v.second;
    int damage = v.first;

    if (finish) {
      if (h <= damage) ans++;
      else {
	int cnt = h / damage;
	h -= damage * cnt;
	if (h == 0) ans += cnt;
	else {
	  ans += cnt + 1;
	}
      }
      cout << ans << endl;
      return 0;
    } else {
      h -= damage;
      ans++;
      if (h <= 0) {
	cout << ans << endl;
	return 0;
      }
    }
  }
  return 0;
}
