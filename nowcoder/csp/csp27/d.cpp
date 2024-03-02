#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<set<int>> goods;
vector<int> ticket;

void solve1(int n, int m, int q)
{
    goods.resize(m + 1);
    ticket.resize(n + 1, 0);
    while(q --)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for(int i=l;i<=r;i++) ticket[i] = x;
        }
        else if(op == 2)
        {
            int x, w; cin >> x >> w;
            for(int i=1;i<=n;i++)
                if(ticket[i] == x) ticket[i] = w;
        }
        else if(op == 3)
        {
            int x, y; cin >> x >> y;
            for(int i=1;i<=n;i++)
                if(ticket[i] == x) ticket[i] = y;
                else if(ticket[i] == y) ticket[i] = x;
        }
        else if(op == 4)
        {
            int w; cin >> w;
            int ans = 0;
            for(int i=1;i<=n;i++) if(ticket[i] == w) ans ++;
            cout << ans << endl;
        }
        else if(op == 5)
        {
            map<int, int> mp;
            for(int i=1;i<=n;i++) if(ticket[i]) mp[ticket[i]] ++;
            int ans = 0, val = 0;
            for(auto &p : mp)
                if(p.second > val) val = p.second, ans = p.first;
            
            cout << ans << endl;
        }
    }
}

using pii = pair<int, int>;
void solve2(int n, int m, int q)
{
    set<pii> st;
    while(q --)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l, r, x; cin >> l >> r >> x;
            auto it = st.lower_bound({l, r});
            if(it != st.end() and )
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    solve1(n, m, q);
    return 0;
}