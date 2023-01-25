#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int h, m;
        cin >> h >> m;
        vector<int> ans;
        //ans.push_back(h*60+m);
        while (n--)
        {
            int hr, mi;
            cin >> hr >> mi;
            ans.push_back(hr * 60 + mi);
        }
        sort(ans.begin(), ans.end());
        int res = 0;
        bool ret = false;
        for(int i=0;i<ans.size();i++) if(ans[i] >= h * 60 + m) {ret = true; res = ans[i]; break;}
        if(!ret) res = ans.front() + 1440 - h * 60 - m;
        else res -= h * 60 + m;

        cout << res / 60 << ' ' << res % 60 << endl;
        
    }
    
    return 0;
}