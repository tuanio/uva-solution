#include <bits/stdc++.h>

using namespace std;

vector<pair<string, string>> glob, borrowed, returned;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  while (getline(cin, s)) {
    if (s == "END") break;
    int i = s.find("by");
    string title = s.substr(0, i - 1);
    string author = s.substr(i + 3, s.size());
    glob.push_back({author, title});
  }
  while (cin >> s && s != "END") {
    if (s[0] == 'B') {
      cin.ignore();
      getline(cin, s);  
      for (int i = 0; i < glob.size(); i++) {
        if (glob[i].second == s) {
          borrowed.push_back({glob[i].first, glob[i].second});
          glob.erase(begin(glob) + i); 
          break;
        } 
      } 
    } else if (s[0] == 'R') {
      cin.ignore();
      getline(cin, s);
      for (int i = 0; i < borrowed.size(); i++) {
        if (borrowed[i].second == s) {
          returned.push_back({borrowed[i].first, borrowed[i].second});
          glob.push_back({borrowed[i].first, borrowed[i].second});
          borrowed.erase(begin(borrowed) + i);
          break;
        }
      }
    } else if (s[0] == 'S') {
      sort(begin(glob), end(glob));
      sort(begin(returned), end(returned));
      for (auto book : returned) {
        for (int i = 0; i < glob.size(); i++) {
          if (book.second == glob[i].second) {
            cout << "Put" << ' ' << book.second << ' ';
            if (i == 0) cout << "first";
            else cout << "after " << glob[i - 1].second;
            cout << '\n';
            break;
          }  
        }
      }
      cout << "END" << '\n';
      returned.clear();
    }  
  } 
  return 0;
}
