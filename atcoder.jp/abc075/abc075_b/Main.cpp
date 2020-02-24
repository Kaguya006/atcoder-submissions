#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector< vector<char> > Graph(H);
  for (int i = 0; i < H; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < W; j++) {
      Graph[i].push_back(str[j]);
    }
  }

  vector< pair<int, int> > eightside = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, 
                                         {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j ++) {
      if (Graph[i][j] == '.') {
        int cnt = 0;
        for (int k = 0; k < eightside.size(); k++) {
          int a = i + eightside[k].first;
          int b = j + eightside[k].second;
          if (0 <= a && a < H && 0 <= b && b < W && Graph[a][b] == '#') cnt++;
        }
        Graph[i][j] = '0' + cnt;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << Graph[i][j];
    }
    cout << '\n';
  }

  return 0;
}
