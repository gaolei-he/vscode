#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<string, int> PII;
int main()
{
    string s[3];
    int n;
    cin >> n;
    vector<PII> a;
    while (n--)
    { 
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s+3);
        a.push_back({s[0]+' '+s[1]+' '+s[2], 1});
    }
    sort(a.begin(), a.end());
    int ma = 1;
    for (int i=0, j=0;i<a.size();i++)
    {
        while(j<a.size()&&a[i].first==a[j].first) j++;
        ma = max(ma, j-i);

    }
    cout << ma;
    return 0;
}