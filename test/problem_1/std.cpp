#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int m, n, q;
    std::cin >> m >> n >> q;
    std::map<std::string, std::string> key_pair;
    for(int i=0;i<m;i++) {
        std::string pub, pri;
        std::cin >> pub >> pri;
        key_pair[pri] = pub;
    }
    std::map<std::string, std::set<std::string>> hosts;
    for (int i=0;i<n;i++) {
        std::string IPv4;
        int k;
        std::cin >> IPv4 >> k;
        for (int j=0;j<k;j++) {
            std::string name;
            int t;
            std::cin >> name >> t;
            std::string key = IPv4 + " " + name;
            for(int cnt=0;cnt<t;cnt++) {
                std::string pub;
                std::cin >> pub;
                hosts[key].insert(pub);
            }
        }
    }

    while(q --) {
        std::string user, ip, pri;
        std::cin >> user >> ip >> pri;
        std::string pub = key_pair[pri];
        std::string key = ip + " " + user;
        if(hosts[key].count(pub)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}