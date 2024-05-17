#include <bits/stdc++.h>
#define int long long
using i64 = long long;

int n, m;
std::vector<std::vector<int>> g;
std::vector<int> record;
std::vector<int> tr;
std::vector<std::pair<int, int>> border;
std::vector<int> idx_ver, ver_idx;
std::vector<std::pair<int, int>> tmp;

int lowbit(int x) {
  return x & (-x);
}

void add(int x, int c) {
  for(int i=x;i<=n;i+=lowbit(i)) {
    tr[i] += c;
  }
}
int sum(int x) {
  int res = 0;
  for(int i=x;i;i-=lowbit(i)) {
    res += tr[i];
  }
  return res;
}

void merge(int idx) {
  int total = record[idx];
  auto vec = std::move(g[idx]);
  for (auto id : vec) {
    total += record[id];
    if (g[idx].size() < g[id].size()) {
      std::swap(g[idx], g[id]);
    }
    for (auto x : g[id]) {
      g[idx].push_back(x);
    }
  }
  record[idx] = total;
  int l = border[idx].first, r = border[idx].second;
  // std::cerr << l << " " << r << "#";
  if(l != -1) {
    add(ver_idx[l], -1);
    add(ver_idx[r] + 1, 1);
  }
  std::cout << g[idx].size() << " " << total << "\n";
}
void init() {
  record.resize(n + 1);
  g.resize(n + 1);
  tr.resize(1);
  border.resize(n + 1);
  ver_idx.resize(n + 1);
  idx_ver.resize(n + 1);
}
void build(int idx, int dep) {
  ver_idx[idx] = tr.size();
  idx_ver[tr.size()] = idx;
  tr.push_back(0);
  for (auto x : g[idx]) {
    build(x, dep + 1);
  }
  if (g[idx].size()) {
    int stx = g[idx].front();
    int edx = idx_ver[tr.size()-1];
    // std::cerr << stx << " " << edx << "$";
    border[idx] = std::make_pair(stx, edx);
  } else {
    border[idx] = std::make_pair(-1, -1);
  }
  tmp.emplace_back(ver_idx[idx], dep);
}
void query(int idx) {
  int ans = sum(ver_idx[idx]);
  std::cout << ans << "\n";
}

void solve() {
  std::cin >> n >> m;
  init();
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  build(1, 1);
  for (auto [idx, dep] : tmp) {
    add(idx, dep);
    add(idx + 1, -dep);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    record[i] = x;
  }
  // for(int i=1;i<=n;i++) {
  //   std::cerr << ver_idx[i] << " " << idx_ver[i] << "\n";
  // }
  while (m--) {
    int op, idx;
    std::cin >> op >> idx;
    if (op == 1) {
      merge(idx);
    } else {
      query(idx);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}