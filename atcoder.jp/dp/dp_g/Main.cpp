#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
vector<int> edge[nax];
int con[nax];
int dist[nax];
bool visited[nax];

void dfs(int a) {
  assert(!visited[a]);
  visited[a] = true;

  for (int b : edge[a]) {
    dist[b] = max(dist[a] + 1, dist[b]);
    --con[b];
    if (con[b] == 0) {
      dfs(b);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    ++con[b];
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i] && con[i] == 0) {
      dfs(i);
    }
  }

  int ans;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dist[i]);
  }
  cout << ans << endl;
}
