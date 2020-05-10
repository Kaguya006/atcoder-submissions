#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");

int main() {
  int n, k;
  cin >> n >> k;

  map<int, int> Map;
  for (int i = 1; i <= n; i++) Map.insert(make_pair(i, 0));

  for(int i = 0; i < k; i++) {
    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int a;
      cin >> a;
      Map.at(a) += 1;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (Map.at(i) == 0) ++ans;
  }
  
  cout << ans << endl;
  return 0;
}
