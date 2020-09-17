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
  string s;
  cin >> s;
  int q;
  cin >> q;

  bool rev = false;
  vector<char> head, tail;
  rep (i, q) {
    int t;
    cin >> t;
    
    if (t == 1) {
      if (!rev) rev = true;
      else rev = false;
      vector<char> tmp = head;
      head = tail;
      tail = tmp;
      //reverse
    } else if (t == 2) {
      int f;
      char c;
      cin >> f >> c;

      if (f == 1) {
	// insert to front.
	head.push_back(c);
      } else {
	// insert to back.
	tail.push_back(c);
      }
    }
  }


  string s1 = "";
  string s2 = "";
  reverse(head.begin(), head.end());
  for (auto v : head) s1 += v;
  for (auto v : tail) s2 += v;

  if (rev) reverse(s.begin(), s.end());
  

  cout << s1 + s + s2 << endl;

  return 0;
}
