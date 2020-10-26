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

struct UnionFind {
    vector<int> a;
    UnionFind(int n) : a(n) {
        for(int i = 0; i < n; i++) a[i] = i;
    }

    int root(int x) { 
        if (a[x] == x) return x;
        return a[x] = root(a[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        a[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    } 
};


int main() {
  //cin.tie(0);ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15);
  int N, M;
  
  cin >> N >> M;
  vector<ll> a(N);
  vector<ll> b(N);
  rep (i, N) cin >> a[i];
  rep (i, N) cin >> b[i];

  UnionFind uf(N);
  rep (i, M) {
    int c, d;
    cin >> c >> d;
    --c; --d;
    uf.unite(c, d);
  }

  map<ll, ll> mp;
  rep (i, N) {
    mp[uf.root(i)] += a[i];
    mp[uf.root(i)] -= b[i];
  }

  for (auto v : mp) {
    if (v.second == 0) continue;
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  
  return 0;
}
