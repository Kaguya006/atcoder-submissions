#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int h, w;
queue< pi > qpi;
vector<char> Graph[1000];

int bfs() {
  int cnt = 0;
  bool flg;
  vector< pi > side = { pi(1,0), pi(-1, 0), pi(0, 1), pi(0, -1) };
  while (!qpi.empty()) {
    flg = false;
    int size = qpi.size();
    for (int i = 0; i < size; i++) {
      pi current = qpi.front();
      qpi.pop();

      for (auto z : side) {
        int x, y;
        x = current.second + z.second; y = current.first + z.first;
        if (0 <= x && x < w && 0 <= y && y < h && Graph[y][x] == '.') {
          flg = true;
          Graph[y][x] = '#';
          qpi.push(make_pair(y, x));
        }
      }
    }
    if (flg) ++cnt;
  }
  return cnt;
}

int main() {
  scanf("%d %d", &h, &w);

  pi start;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < w; j++) {
      if (s[j] == '#') {
        qpi.push(make_pair(i, j));
      }
      Graph[i].push_back(s[j]);
    }
  }
  cout << bfs() << endl;

  return 0;
}
