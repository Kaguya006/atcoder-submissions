#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");

int main() {
  int n;
  ull k;
  cin >> n >> k;

  vector<int> graph(n + 1);
  vector<int> visit_nums;
  vector<bool> visit(n + 1);
  rep(i, n) {
    int a;
    cin >> a;
    graph[i + 1] = a;
  }

  int idx = 0;
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      visit[1] = true;
      visit_nums.push_back(1);
      idx = graph[1];
    } else {
      visit[idx] = true;
      visit_nums.push_back(idx);
      idx = graph[idx];
    }

    if (visit[idx] == true) {
      ////ringBuffer
      //cout << "i=" << i << endl;
      //cout << "idx=" << idx << endl;
      //cout << "graph[idx]=" << graph[idx] << endl;
      auto start_iter = find(visit_nums.begin(), visit_nums.end(), idx);
      visit_nums.erase(visit_nums.begin(), start_iter);
      int ans_idx = (k - i) % visit_nums.size();

      cout << visit_nums[ans_idx] << endl;
      return 0;
    }
  }

  cout << idx << endl;
  return 0;
}
