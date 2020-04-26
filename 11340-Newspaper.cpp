#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    double money = 0;
    map<char, double> cnt;
    int n; cin >> n;
    while (n--) {
      char a; double p;
      cin >> a >> p;
      cnt[a] = p;
    }
    cin >> n; cin.ignore();
    while (n--) {
      string s; getline(cin, s);
      for (char c : s) money += cnt[c];
    }
    cout << fixed << setprecision(2) << money / 100.0F << "$\n";
  }
  return 0;
}
