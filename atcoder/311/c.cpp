// n = int(input())
// a = list(map(int, input().split()))
// g = [[] for _ in range(n+1)]
// for idx, val in enumerate(a):
//     g[idx+1].append(val)
// vis = [False for _ in range(n + 1)]
// ans = []
// st = set()
// def dfs(ver:int):
//     for v in g[ver]:
//         if v in st:
//             print(len(ans[ans.index(v):]))
//             print(*ans[ans.index(v):], sep=' ')
//             exit(0)
//         if not vis[v]:
//             vis[v] = True
//             st.add(v)
//             ans.append(v)
//             dfs(v)
//             ans.pop()

// for i in range(1, n+1):
//     ans.append(i)
//     st.add(i)
//     dfs(i)
//     st.clear()
//     ans.clear()
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> g;
vector<bool> vis;
vector<int> ans;
unordered_set<int> st;

void dfs(int ver) {
    for (int v : g[ver]) {
        if (st.find(v) != st.end()) {
            cout << ans.size() - (find(ans.begin(), ans.end(), v) - ans.begin()) << endl;
            for (auto it = find(ans.begin(), ans.end(), v); it != ans.end(); ++it) {
                cout << *it << ' ';
            }
            cout << endl;
            exit(0);
        }
        if (!vis[v]) {
            vis[v] = true;
            st.insert(v);
            ans.push_back(v);
            dfs(v);
            ans.pop_back();
        }
    }
}

int main() {
    cin >> n;
    g.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        g[i].push_back(val);
    }

    for (int i = 1; i <= n; ++i) {
        ans.push_back(i);
        vis[i] = true;
        st.insert(i);
        dfs(i);
        st.clear();
        ans.clear();
    }

    return 0;
}
