#include <bits/stdc++.h>
#define int long long
using i64 = long long;

struct Node {
    Node() { LD = LR = remLD = remLR = 0; }
    Node(std::string file_name, bool isFile, int size, int LD, int LR) {
        this->file_name = file_name;
        this->isFile = isFile;
        this->size = size;
        this->LD = LD;
        this->LR = LR;
        remLR = remLD = 0;
    }
    std::string file_name;
    bool isFile;
    int size;
    int LD, LR;
    int remLD, remLR;
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id = 0;
    std::unordered_map<std::string, std::unordered_set<std::string>> g;
    std::unordered_map<std::string, Node> mp;
    g["/"] = {};
    mp["/"] = Node("/", false, 0, 0, 0);
    int n;
    std::cin >> n;
    auto create_file = [&](std::string file_path, int file_size) {
        int val = 0;
        std::vector<std::pair<std::string, std::string>> tmp_vec;
        std::vector<std::string> vec;
        std::string name;
        for (auto c : file_path) {
            if (c == '/' and name.size()) {
                vec.push_back(name);
                name.clear();
                continue;
            } else if (c == '/') {
                continue;
            }
            name.push_back(c);
        }
        vec.push_back(name);

        name = "/";
        int mi = -1;
        for (int i = 0; i < vec.size(); i++) {
            std::string &s = vec[i];
            std::string file_name;
            if (mp.count(name) and mp[name].LR != 0) {
                if (mi == -1) {
                    mi = mp[name].remLR;
                }
                mi = std::min(mi, mp[name].remLR);
            }
            if (i == vec.size() - 1 and mp.count(name) and mp[name].LD != 0) {
                if (mi == -1) {
                    mi = mp[name].remLD;
                }
                mi = std::min(mi, mp[name].remLD);
            }
            if (name.length() == 1) {
                file_name = name + s;
            } else {
                file_name = name + "/" + s;
            }
            if (i == vec.size() - 1) {
                int cnt = 0;
                if (g[name].count(file_name)) {
                    cnt = mp[file_name].size;
                }
                if (mi != -1 and file_size - cnt > mi or
                    g[name].count(file_name) and !mp[file_name].isFile) {
                    return false;
                }
                val = file_size - cnt;
                for (auto &s : tmp_vec) {
                    if (!g[s.first].count(s.second)) {
                        g[s.first].insert(s.second);
                        mp[s.second] = Node(s.second, false, 0, 0, 0);
                    }
                }
                mp[file_name] = Node(file_name, true, file_size, 0, 0);
                g[name].insert(file_name);
            } else {
                tmp_vec.emplace_back(name, file_name);
                if (g[name].count(file_name) and mp[file_name].isFile) {
                    return false;
                }
            }

            name = file_name;
        }

        name = "/";
        for (int i = 0; i < vec.size(); i++) {
            std::string &s = vec[i];
            std::string file_name;
            if (mp[name].LR != 0) {
                mp[name].remLR -= val;
            }
            if (i == vec.size() - 1 and mp[name].LD != 0) {
                mp[name].remLD -= val;
            }
            if (name.length() == 1) {
                file_name = name + s;
            } else {
                file_name = name + "/" + s;
            }
            name = file_name;
        }
        return true;
    };

    auto remove_file = [&](std::string file_path) {
        int val = 0, tmp_val = 0;
        std::vector<std::string> vec, tmp_vec;
        std::string name;
        for (auto c : file_path) {
            if (c == '/' and name.size()) {
                vec.push_back(name);
                name.clear();
                continue;
            } else if (c == '/') {
                continue;
            }
            name.push_back(c);
        }
        vec.push_back(name);
        tmp_vec = vec;
        name = "/";
        for (int i = 0; i < vec.size(); i++) {
            std::string &s = vec[i];
            std::string file_name;
            if (name.length() == 1) {
                file_name = name + s;
            } else {
                file_name = name + "/" + s;
            }

            if (!g[name].count(file_name)) {
                break;
            }
            if (i == vec.size() - 1) {
                if (mp[file_name].isFile) {
                    tmp_val = val = mp[file_name].size;
                    mp.erase(file_name);
                    g[name].erase(file_name);
                } else {
                    vec.clear();
                    std::queue<std::string> q;
                    q.push(file_name);

                    while (q.size()) {
                        auto s = q.front();
                        vec.push_back(s);
                        q.pop();
                        for (auto t : g[s]) {
                            q.push(t);
                        }
                    }
                    g[name].erase(file_name);
                    for (auto &s : vec) {
                        val += mp[s].size;
                        g.erase(s);
                        mp.erase(s);
                    }
                }
                break;
            }
            name = file_name;
        }

        name = "/";
        for (int i = 0; i < tmp_vec.size(); i++) {
            std::string &s = tmp_vec[i];
            std::string file_name;
            if (name.length() == 1) {
                file_name = name + s;
            } else {
                file_name = name + "/" + s;
            }
            if (mp.count(name) and mp[name].LR != 0) {
                mp[name].remLR += val;
            }
            if (i == tmp_vec.size() - 1 and mp.count(name) and
                mp[name].LD != 0) {
                mp[name].remLD += tmp_val;
            }

            name = file_name;
        }

        return true;
    };
    auto set_file = [&](std::string file_path, int LD, int LR) {
        if (!mp.count(file_path) or mp[file_path].isFile) {
            return false;
        }

        int sm = 0;
        for (auto &s : g[file_path]) {
            sm += mp[s].size;
        }
        if (LD and sm > LD) {
            return false;
        }
        int tmp_sm = sm;
        sm = 0;
        std::queue<std::string> q;
        q.push(file_path);
        while (q.size()) {
            auto s = q.front();

            sm += mp[s].size;
            q.pop();
            for (auto &v : g[s]) {
                q.push(v);
            }
        }

        if (LR and sm > LR) {
            return false;
        }
        mp[file_path].LD = LD;
        mp[file_path].remLD = std::max(0ll, LD - tmp_sm);
        mp[file_path].LR = LR;
        mp[file_path].remLR = std::max(0ll, LR - sm);
        return true;
    };
    while (n--) {
        char op;
        std::string file_path;
        int file_size, LR, LD;
        bool flag;
        std::cin >> op;
        if (op == 'C') {
            std::cin >> file_path >> file_size;
            flag = create_file(file_path, file_size);
        } else if (op == 'R') {
            std::cin >> file_path;
            flag = remove_file(file_path);
        } else if (op == 'Q') {
            std::cin >> file_path >> LD >> LR;
            flag = set_file(file_path, LD, LR);
        }
        if (flag) {
            std::cout << "Y\n";
        } else {
            std::cout << "N\n";
        }
    }

    return 0;
}