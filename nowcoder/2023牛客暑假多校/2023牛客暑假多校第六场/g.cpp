#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define inf 0x3f3f3f3f
#define int long long
#define all(x) x.begin(), x.end()
constexpr int N = 2e5 + 10;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x < y) swap(x, y);
    if (x == 0 or y == 0) {
      if (x == y) {
        cout << (z ? "NO" : "YES") << "\n";
      } else if (y == 0) {
        cout << (z % x ? "NO" : "YES") << "\n";
      }
      continue;
    }

    bool ans = false;
    if (z % __gcd(x, y) == 0) ans = true;
    cout << (ans ? "YES" : "NO") << "\n";
  }

  return 0;
}