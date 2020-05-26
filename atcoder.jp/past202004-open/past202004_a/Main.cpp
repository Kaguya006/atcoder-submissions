#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");

int main() {
  string s, t;
  cin >> s >> t;
  vector<string> elevator;

  rep(i, 9) elevator.push_back("B" + to_string(i + 1));
  reverse(elevator.begin(), elevator.end());
  rep(i, 9) elevator.push_back(to_string(i + 1) + "F");

  int dis1 = find(elevator.begin(), elevator.end(), s) - elevator.begin();
  int dis2 = find(elevator.begin(), elevator.end(), t) - elevator.begin();
  
  cout << abs(dis1 - dis2) << endl;

  return 0;
}
