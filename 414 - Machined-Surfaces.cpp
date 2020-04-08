#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n && n) {
    cin.ignore();
    int mn = 1e9 + 1;
    vector<int> a;
    while (n--) {
      string s; getline(cin, s);
      int cnt = 0;
      for (char c : s) {
        cnt += c == ' ';
      }
      mn = min(mn, cnt);
      a.push_back(cnt);
    }
    int ans = 0;
    for (int i : a) {
      ans += i - mn;
    }
    cout << ans << '\n';
  }
  return 0;
}
