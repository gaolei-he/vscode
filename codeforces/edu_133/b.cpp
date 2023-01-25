#include <iostream>
#include <cstring>
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
        scanf("%d", &n);
        vector<int> a;
        printf("%d\n", n);
        for(int i=1;i<=n;i++) a.push_back(i);
        for(int i=n;i;i--)
        {
            for(auto j:a) printf("%d ", j);
            puts("");
            if(i!=1) swap(a[i-1], a[i-2]);

        }
    }
    
    
    return 0;
}