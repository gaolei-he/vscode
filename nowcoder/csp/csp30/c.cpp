#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pcc = pair<char, char>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    string text = "";
    char c;
    while(cin >> c) text.push_back(c);
    bool fin = true;
    auto f = [&](pcc p, bool flag, bool symbol = false)
    {
        int res = 0;
        if(p.second < 'a') res += p.second - '0';
        else res += p.second - 'a' + 10;
        if(p.first < 'a') res += (p.first - '0') * 16;
        else res += (p.first - 'a' + 10) * 16;
        if(flag and res < 128 and symbol) fin = false;
        else if(!flag and res >= 128 and symbol) fin = false;
        if(flag) res ^= (1 << 7);
        // if(!fin) cerr << "f " << p.first << p.second << endl;
        return res;
    };
    queue<pcc> q;
    vector<pcc> ans;
    auto output = [&](vector<pcc> &s)
    {
        int cnt = 0;
        for(auto c : s)
        {
            cnt ++;
            cout << c.first << c.second;
            if(cnt == 8) cout << endl, cnt = 0;
        }
    };
    auto yinyong = [&](int o, int l)
    {
        // cerr << "o l " << o << ' ' << l << endl;
        int p = ans.size();
        vector<pcc> tmp;
        if(o >= l) rep(i, 0, l - 1) tmp.push_back(ans[p - o + i]);
        else
        {
            int i = 0;
            while(tmp.size() < l)
            {
                if(i == o) i = 0;
                tmp.push_back(ans[p - o + i]);
                i ++;
            }
        }
        for(auto c : tmp) ans.push_back(c);
    };
    auto f0 = [&](int op)
    {
        int cnt = op >> 2;
        cnt += 1;
        // cerr << "$" << cnt << endl;
        if(cnt <= 60) while(cnt --) ans.push_back(q.front()), q.pop();
        else
        {
            cnt -= 60;
            int nums = 1;
            int R = 1;
            // cerr << "f0 " << cnt << " " << q.front().first << q.front().second << endl;
            while(cnt --) nums += f(q.front(), false) * R, q.pop(), R *= 256;
            // cerr << "#" << nums << " " << fin << "$" << endl;
            while(nums --) ans.push_back(q.front()), q.pop();
        }
    };
    auto f1 = [&](int op)
    {
        int o = f(q.front(), false);
        q.pop();
        o += (op >> 5) * 256;
        int l = (op >> 2) & 0b111;
        l += 4;
        yinyong(o, l);
    };
    auto f2 = [&](int op)
    {
        int l = op >> 2;
        l += 1;
        int o = f(q.front(), false);
        q.pop();
        o += f(q.front(), false) * 256;
        q.pop();
        yinyong(o, l);
    };
    rep(cnt, 1, 4)
    {
        q = queue<pcc>();
        ans.clear();
        fin = true;
        for(int i = 0; i < text.size(); i += 2) q.push({text[i], text[i + 1]});
        int total = 0;
        int R = 1;
        int tmp = cnt;
        while(tmp --)
        {
            if(tmp) total += f(q.front(), true, true) * R, q.pop();
            else total += f(q.front(), false, true) * R, q.pop();
            R *= 128;
        }// get the number of characters
        // cerr << total << endl;
        if(!fin) continue;// 引导区能被解析出正确数值

        while(q.size())
        {
            int nums_of_ele = f(q.front(), false);
            // cerr << "hex" << q.front().first << q.front().second << endl;
            q.pop();
            int op = nums_of_ele & 3;
            // cerr << op << endl;
            if(op == 0) f0(nums_of_ele);
            else if(op == 1) f1(nums_of_ele);
            else if(op == 2) f2(nums_of_ele);
            else fin = false;
            // cerr << "#" << q.size() << ' ' << fin << endl;

            if(!fin) break;
        }
        if(fin)
        {
            output(ans);
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}