#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

#define rep(i, a, n) for(int i=(a);i<=(n);++i)

using namespace std;

unordered_map<string, vector<unordered_set<string>>> users;
unordered_map<string, vector<vector<string>>> privileges;
unordered_map<string, vector<string>> groups;
unordered_map<string, vector<string>> friends;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        string name; cin >> name;
        users[name].resize(3);
        auto &vec = users[name];
        rep(j, 0, 2)
        {
            int cnt; cin >> cnt;
            rep(k, 1, cnt)
            {
                string op; cin >> op;
                vec[j].insert(op);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        string name; cin >> name;
        privileges[name].resize(2);
        auto &vec = privileges[name];
        int ns; cin >> ns;
        rep(j, 1, ns)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if(s1 == "u") vec[0].push_back(s2), friends[s2].push_back(name);
            else vec[1].push_back(s2), groups[s2].push_back(name);
        }
    }
    
    auto check = [&](string &user, string &owner, string &s1, string &s2, string &s3)
    {
        if(!users.count(owner)) return false;
        auto &vec = users[owner];
        if(!vec[0].count(s1) and !vec[0].count("*")) return false;
        if(!vec[1].count(s2) and !vec[1].count("*")) return false;
        if(vec[2].size() and !vec[2].count(s3)) return false;
        return true;
    };
    while(q --)
    {
        string name; cin >> name;
        int val; cin >> val;
        vector<string> group(val);
        for(auto &x : group) cin >> x;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        bool ans = false;
        if(check(name, name, s1, s2, s3)) ans = true;
        if(privileges.count(name))
        for(auto &user : privileges[name][0])
        {
            if(check(name, user, s1, s2, s3))
            {
                ans = true;
                break;
            }
        }
        if(friends.count(name))
        for(auto &user : friends[name])
        {
            if(ans) break;
            if(check(name, user, s1, s2, s3))
            {
                ans = true;
                break;
            }
        }
        for(auto &g : group)
        {
            if(ans) break;
            if(groups.count(g))
            for(auto &user : groups[g])
            {
                if(check(name, user, s1, s2, s3))
                {
                    ans = true;
                    break;
                }
            }
        }
        if(ans) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}

// 1 2 3
// op 1 open 1 door 0
// op 1 g sre
// op 1 u xiaop
// xiaoc 2 sre ops open door room302
// xiaop 1 ops open door room501
// xiaoc 2 sre ops remove door room302