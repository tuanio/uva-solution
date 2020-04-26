#include <bits/stdc++.h>

using namespace std;

const int M = 3001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    bitset<M> bs;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (int i = 0; i < n - 1; i++) 
      bs[abs(a[i] - a[i + 1])] = true;
    bool flag = true;
    for (int i = 1; i < n; i++) flag &= bs[i];
    cout << (flag ? "Jolly" : "Not jolly") << '\n';
  }
  return 0;
}
