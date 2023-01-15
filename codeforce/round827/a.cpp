#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a;
        for (int i = 0; i < 3; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        if(a[0] + a[1] == a[2]) puts("YES");
        else puts("NO");
        
    }
    
    return 0;
}