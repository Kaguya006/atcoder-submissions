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
  int x, y;
  cin >> x >> y;


  ll ans = 0;
  // -5 -> -2 (ans += 3)
  // -5 -> 2  (ans += 7)
  // 2 -> 5   (ans += 3)
  
  // -2 -> -5 (ans += 3 + 2)
  // 7 -> 2 (ans += 5 + 2)  
  // 2 -> -5  (ans += 4)

  if (abs(x) == abs(y)) {
    cout << 1 << endl;
    return 0;
  }

  if (x == 0 || y == 0) {
    if (x == 0) {
      if (y < 0) {
	ans += abs(y - x) + 1;
      } else {
	ans += abs(y - x);
      }
    } else {
      if (x < 0) {
	ans += abs(y - x);
      } else {
	ans += abs(y - x) + 1;
      }
    }
  } else {
    if (-1 < x && -1 < y) {
      ans += abs(y - x);
      if (x > y) {
	ans += 2;
      }
    } else if (x < 0 && y < 0) {
      ans += abs(y - x);
      if (x > y) {
	ans += 2;
      }
    } else {      
      ans += abs(abs(x) - abs(y)) + 1;
    }
  }
  
  cout << ans << '\n';
  return 0;
}
