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
  ll x = 10000000000;

  int n;
  string t;
  cin >> n >> t;

  for (int i = 2; i < t.size(); i++) {
    if (t[i - 2] == '1') {
      if (t[i - 1] == '1') {
        if (t[i] != '0') {
          cout << 0 << endl;
          exit(0);
        }
      } else if (t[i - 1] == '0') {
        if (t[i] != '1') {
          cout << 0 << endl;
          exit(0);
        }
      }
    } else if (t[i - 2] == '0') {
      if (t[i - 1] == '1' && t[i] == '1') {
        continue;
      } else {
        cout << 0 << endl;
        exit(0);
      }
    }
  }

  if (t == "1") {
    cout << 2 * x << endl;
  }else if (t == "00") {
    cout << 0 << endl;
  } else if (t == "11" || t == "0" || t == "10") {
    cout << x << endl;
  } else {
    if (t[0] == '0') {
      // 0110110 -> 110110
      t = t.substr(1);
      x--;
    } else if (t[0] == '1' && t[1] == '0') {
      // 10110110 -> 110110
      t = t.substr(2);
      x--;
    }

    if (t.size() > 2) {
      x = (x - (t.size() / 3)) + 1;
      if (t.size() % 3) x--;
    }
    cout << x << endl;
  }

  return 0;
}
