#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans;
        set<string> a;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            ans.push_back(tmp);
            a.insert(tmp);
        }
        int cnt = 0;
        for(auto i:ans)
        {
            string t1, t2;
            bool flag = false;

            for(int j=1;j<i.size();j++)
            {
                t1 = i.substr(j);
                auto tmp = i;
                tmp.erase(tmp.begin()+j, tmp.end());
                t2 = tmp;
                //cout << endl << t2 << t1 << endl;
                if(a.find(t1) != a.end() && a.find(t2) != a.end()) {flag = true; break;}
            }
            if(flag) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    return 0;
}