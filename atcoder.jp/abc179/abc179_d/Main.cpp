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
//const int MOD = 1e9 + 7;
const int MOD = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct mint {
  ll x;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

// pow mod
mint powm(ll a, ll n) {
  mint res = 1;
  mint x = a;
  while (n > 0) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}


int main() {
  //cin.tie(0);ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15);
  int n, k;
  cin >> n >> k;
  vector<int> l(n), r(n);
  rep (i, k) {
    cin >> l[i] >> r[i];
  }

  vector<mint> dp(n + 1);
  vector<mint> dpsum(n + 1);
  dp[1] = 1;
  dpsum[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      int li = i - r[j];
      int ri = i - l[j];

      if (ri <= 0) continue;
      li = max(li, 1);

      mint t = dpsum[ri] - dpsum[li - 1];
      dp[i] += t;
      dpsum[i] += t;
    }
    dpsum[i] += dpsum[i - 1];
  }

  cout << dp[n].x << '\n';
  return 0;
}
