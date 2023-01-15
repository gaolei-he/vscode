#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        bool flag = true;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i+1] == a[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    
    return 0;
}