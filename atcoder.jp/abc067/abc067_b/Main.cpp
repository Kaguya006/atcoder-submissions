#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> tails(n);
  for (int i = 0; i < n; i++) {
    cin >> tails[i];
  }

  sort(tails.begin(), tails.end());
  reverse(tails.begin(), tails.end());

  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += tails[i];
  }

  cout << sum << endl;

  return 0;
}
