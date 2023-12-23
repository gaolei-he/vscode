#include <iostream>
#include <vector>
#include <set>

using namespace std;
using pii = pair<int, int>;

vector<set<pii>> tasks; // index = available distinct, val = application
vector<set<pii>> antitasks; // index = calc points
vector<int> query;

int main()
{
    int n, m; cin >> n >> m;
    tasks.resize(m + 1);
    antitasks.resize(n + 1);
    query.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        query[i + 1] = x;
    }


    auto check = [&](int a, int na, int pa, int paa, int paar, int &point, int k, int op = 1)
    {
        if(na and query[k] != na) return;
        if(pa)
        {
            auto it = tasks[query[k]].lower_bound({pa, 0});
            if(it == tasks[query[k]].end() or it->first != pa) return;
        }

        if(op == 1 and paa)
        {
            auto it = antitasks[k].lower_bound({paa, 0});
            if(it != antitasks[k].end() and it->first == paa) return;
        }

        if(point == 0 or antitasks[k].size() < antitasks[point].size()) point = k;
    };

    int g; cin >> g;
    for(int i=1;i<=g;i++)
    {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        for(int j=1;j<=f;j++)
        {
            int point = 0;
            for(int k=1;k<=n;k++) check(a, na, pa, paa, paar, point, k);

            if(paar == 0 and point == 0) for(int k=1;k<=n;k++) check(a, na, pa, paa, paar, point, k, 0);
            cout << point << ' ';

            antitasks[point].insert(make_pair(a, antitasks[point].size()));
            tasks[query[point]].insert(make_pair(a, antitasks[point].size()));
        }
        cout << endl;
    }
    return 0;
}