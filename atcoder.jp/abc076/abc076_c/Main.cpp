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
  string Sd,T;
  cin >> Sd >> T;

  reverse(Sd.begin(), Sd.end());
  reverse(T.begin(), T.end());

  bool ok = false;
  string ans;
  string horn = "";
  for (int i = 0; i + T.size() <= Sd.size(); i++) {
    string head = Sd.substr(i, T.size());
    for (int j = 0; j < head.size(); j++) {
      if (head[j] == '?') head[j] = T[j];
    }
 
    if (head == T) {
      ok = true;
      string horn = Sd.substr(0, i);
      string tail = Sd.substr(i + T.size());
      for (int k = 0; k < tail.size(); k++) {
	if (tail[k] == '?') tail[k] = 'a';
      }
      for (int k = 0; k < horn.size(); k++){
	if (horn[k] == '?') horn[k] = 'a';
      }
      head = horn + head;
      reverse(head.begin(), head.end());
      reverse(tail.begin(), tail.end());
      ans = tail + head;
      break;
    }
  }

  if (ok){
    cout << ans << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  
  return 0;
}
