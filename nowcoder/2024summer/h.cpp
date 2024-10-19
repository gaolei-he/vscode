#include <bits/stdc++.h>
#define int long long
struct Node {
    Node(std::string name, int count, int penalty) {
        this->name = name;
        this->count = count;
        this->penalty = penalty;
    }
    std::string name;
    int count, penalty;
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<Node> vecn, vecm;
    std::set<std::string> st1, st2;
    while (n--) {
        std::string name;
        int count, penalty;
        std::cin >> name >> count >> penalty;
        st1.insert(name);
        vecn.emplace_back(name, count, penalty);
    }
    int m;
    std::cin >> m;
    while (m--) {
        std::string name;
        int count, penalty;
        std::cin >> name >> count >> penalty;
        st2.insert(name);
        vecm.emplace_back(name, count, penalty);
    }
    auto cmp = [](Node a, Node b) {
        if (a.count == b.count) {
            return a.penalty < b.penalty;
        }
        return a.count > b.count;
    };
    std::sort(vecn.begin(), vecn.end(), cmp);
    std::sort(vecm.begin(), vecm.end(), cmp);
    int cnt = 0, rank1 = -1;
    for(int i=0;i<vecn.size();i++) {
        if(vecn[i].name == "lzr010506") {
            rank1 = i + 1 - cnt;
            break;
        } else if(st2.count(vecn[i].name)) {
            cnt += 1;
        }
    }
    int rank2 = -1;
    cnt = 0;
    for(int i=0;i<vecm.size();i++) {
        if(vecm[i].name == "lzr010506") {
            rank2 = i + 1 - cnt;
            break;
        } else if(st1.count(vecm[i].name)) {
            cnt += 1;
        }
    }
    std::cout << std::min(rank1, rank2) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}