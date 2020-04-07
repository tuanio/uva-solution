#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Name {
  int B, D;
  vector<pair<int, int>> bound;
  vector<ll> C;
};

void cal(Name& a, int id) {
  if (!id) {
    a.C[id] = a.B;
    for (int i = 0; i <= a.D; i++) {
      a.C[id] -= (a.C[i] * a.bound[i].first);      
    }
    return;
  }
  a.C[id] = a.C[id + 1] * (a.bound[id + 1].second - a.bound[id + 1].first + 1);
  cal(a, id - 1);
} 

map<string, Name> ma;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  while (n--) {
    string s; int b, cd, d; 
    cin >> s >> b >> cd >> d;
    
    Name foo;
    foo.B = b;
    foo.D = d;
    foo.C.resize(d + 1);
    foo.C[d] = cd;
    foo.bound.push_back({0, 0});

    for (int i = 0; i < d; i++) {
      int l, r; cin >> l >> r;
      foo.bound.push_back({l, r});
    }
    
    cal(foo, d - 1);
    ma[s] = foo;
  }
  while (m--) {
    string s; cin >> s;
    vector<int> a(ma[s].D + 1);
    a[0] = 1;
    for (int i = 1; i <= ma[s].D; i++) {
      cin >> a[i];
    }
    // physical address
    ll phyadr = 0;
    for (int i = 0; i <= ma[s].D; i++) {
      phyadr += ma[s].C[i] * a[i] * 1LL;
    }
    cout << s << '[';
    for (int i = 1; i <= ma[s].D; i++) {
      cout << a[i];
      if (i != ma[s].D) 
        cout << ", ";
    }
    cout << "] = " << phyadr << '\n';
  }
  return 0;
}