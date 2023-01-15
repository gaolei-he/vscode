#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<string, string> PII;
int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> ans;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        ans[b] = a;
    }
    vector<PII> ans1;
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        b.pop_back();
        ans1.push_back({a, b});
    }
    for(auto i:ans1)
    {
        cout << i.first << ' ' << i.second << "; #" << ans[i.second] << endl;
    }
    
    

    return 0;
}