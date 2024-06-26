// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <set>
// #include <bitset>
// #include <queue>
// #include <map>
// #include <stack>
// #include <string>
// #include <random>
// #include <cassert>
// #include <functional>
// #include <iomanip>
// #include <array>
// #include <unordered_map>
// #include <unordered_set>
// #define inf 0x3f3f3f3f
// #define linf 0x3f3f3f3f3f3f3f3fll
// #define endl '\n'
// #define ll long long
// #define int long long
// #define ull unsigned long long
// #define SZ(x) (int)x.size()
// #define rep(i, a, n) for (int i = (a); i <= (n); i++)
// #define dec(i, n, a) for (int i = (n); i >= (a); i--)
// using namespace std;
// using pii = pair<int, int>;
// using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
// const int N = 10 + 1e5, mod = 1e9 + 7;
// int a[N];
// void solve()
// {
//     int n; cin >> n;
//     unordered_map<int, int> mp;
//     int root;
//     rep(i, 1, n)
//     {
//         int x; cin >> x;
//         mp[x] = i;
//         if(i == n) root = x;
//     }
//     rep(i, 1, n) cin >> a[i];
//     vector<vector<int>> g(n+1);
//     function<void(int, int, int)> dfs = [&](int l, int r, int p) {
//         if(l >= r) return;
//         int mid;
//         rep(i, l, r) if(a[i] == p) mid = i;
//         int vl = -1, pos = -1;
//         rep(i, l, mid-1) if(pos < mp[a[i]]) pos = mp[a[i]], vl = a[i];
//         pos = -1;
//         int vr = -1;
//         rep(i, mid+1, r) if(pos < mp[a[i]]) pos = mp[a[i]], vr = a[i];
//         if(vl > 0) g[p].push_back(vl);
//         if(vr > 0) g[p].push_back(vr);
//         dfs(l, mid-1, vl);
//         dfs(mid+1, r, vr);
//     };
//     dfs(1, n, root);
//     vector<int> ans;
//     function<void(void)> bfs = [&]() {
//         queue<int> q;
//         q.push(root);
//         while(q.size())
//         {
//             ans.push_back(q.front());
//             int v = q.front();
//             q.pop();
//             for(auto i:g[v]) q.push(i);
//         }
//     };
//     bfs();
//     for(auto v:ans) cout << v << ' ';
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // int t; cin >> t;
//     // while(t--)
//         solve();

//     return 0;
// }
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 构建二叉树
TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& map) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    int rootIndex = map[rootVal];
    int leftSize = rootIndex - inStart;
    root->left = buildTree(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1, map);
    root->right = buildTree(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1, map);
    return root;
}

// 层序遍历
vector<int> levelOrder(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    return result;
}

vector<int> getLevelOrder(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
    TreeNode* root = buildTree(inorder, 0, n - 1, postorder, 0, n - 1, map);
    vector<int> result = levelOrder(root);
    return result;
}

int main() {
    int n; cin >> n;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for(auto& i:postorder) cin >> i;
    for(auto& i:inorder) cin >> i;
    vector<int> result = getLevelOrder(inorder, postorder);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
