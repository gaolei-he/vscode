#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> site, inurl;
    while (n--)
    {
        string tmp;
        cin >> tmp;
        tmp = tmp.substr(5);
        site.push_back(tmp);
        cin >> tmp;
        tmp = tmp.substr(6);
        inurl.push_back(tmp);
    }
    int m;
    cin >> m;
    while (m--)
    {
        string tmp;
        cin >> tmp;
        int i;
        for(i=0;i<site.size();i++)
        {
            if(tmp.find(site[i]) != string::npos && tmp.find(inurl[i]) != string::npos)
            {
                puts("1");
                break;
            }
        }
        if(i == site.size()) puts("0");
    }
    
    
    return 0;
}