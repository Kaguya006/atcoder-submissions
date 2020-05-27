#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
using namespace std;
using P = pair<int,int>;
using ll = long long;

//Get the highest value and key from a map.
template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  });
}

int main() {
  int N;
  cin >> N;

  vector< vector<char> > graph(N);
  rep(i, N) {
    string s;
    cin >> s;
    for (auto ch : s) graph[i].push_back(ch);
  }

  for (int i = N - 2; i >= 0; i--) {
    for (int j = 2 * N - 3; j > 0; j--) {
      if (graph[i][j] != '#') continue;

      char ch1 = graph[i + 1][j - 1];
      char ch2 = graph[i + 1][j];
      char ch3 = graph[i + 1][j + 1];

      if (ch1 == 'X' || ch2 == 'X' | ch3 == 'X') graph[i][j] = 'X';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N - 1; j++) {
      cout << graph[i][j];
    }
    cout << endl;
  }

  return 0;
}
