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
using pii = pair<int, int>;
using ar2 = array<int, 2>;
using pcc = pair<char, char>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
char str[3][N], str2[N];
void solve()
{
    cin >> str[1] + 1 >> str[2] + 1;
    unordered_map<int, pcc> mp;
    for(int i=1;str[1][i];++i) if(str[1][i] != str[2][i]) mp[i] = {str[1][i], str[2][i]};
    set<pii> st;
    int t, q;
    cin >> t >> q;
    rep(i, 1, q)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int pos; cin >> pos;
            if(str[1][pos] == str[2][pos]) continue;
            mp.erase(pos);
            st.insert({t+i, pos});
        }
        else if(op == 2)
        {
            int op1, op2, pos1, pos2;
            cin >> op1 >> pos1 >> op2 >> pos2;
            swap(str[op1][pos1], str[op2][pos2]);
            if(str[1][pos1] == str[2][pos1] and mp.count(pos1)) mp.erase(pos1);
            else if(str[1][pos1] != str[2][pos1]) mp[pos1] = {str[1][pos1], str[2][pos1]};
            if(str[1][pos2] == str[2][pos2] and mp.count(pos2)) mp.erase(pos2);
            else if(str[1][pos2] != str[2][pos2]) mp[pos2] = {str[1][pos2], str[2][pos2]};
        }
        else if(op == 3)
        {
            while(st.size() and st.begin()->first <= i)
            {
                int pos = st.begin()->second;
                st.erase(st.begin());
                mp[pos] = {str[1][pos], str[2][pos]};
            }
            if(mp.size()) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}