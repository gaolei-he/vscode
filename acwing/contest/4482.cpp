#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] ++;
        ans = max(a[x], ans);
    }
    cout << ans;
    
    return 0;
}