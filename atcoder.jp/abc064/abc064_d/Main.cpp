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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int left, right;
  left = right = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') left++;
    else right++;
  }

  //printf("left = %d, right = %d\n", left, right);

  int cnt = 0;
  string ss = s;
  for (int i = 0; i < ss.size(); i++) {
    if (ss[i] == '(') {
      for (int j = i + 1; j < ss.size(); j++) {
	if (ss[j] == ')') {
	  ss[j] = 'x';
	  cnt++;
	  break;
	}
      }
    }
  }
  
  int add_right = left - cnt;
  int add_left = right - cnt;

  //printf("add_right = %d, add_left = %d, cnt = %d\n", add_right, add_left, cnt);
  string ans = s;
  for (int i = 0; i < add_right; i++) ans += ')';
  for (int i = 0; i < add_left; i++) {
    ans = '(' + ans;
  }

  cout << ans << endl;
  return 0;
}
