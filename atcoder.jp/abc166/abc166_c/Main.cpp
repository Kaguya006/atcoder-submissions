#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> height(n);
  for (int i = 0; i < n; i++) cin >> height[i];

  vector< vector<int> > Graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int h = height[i];
    bool flg = true;
    for (auto v : Graph[i]) if (h <= height[v]) flg = false;
    if (flg) ++ans;
  }

  cout << ans << endl;

  return 0;
}
