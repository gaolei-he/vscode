#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if(a!=b && min(a, b) >= m && a+b >= n+m || a==b && a >= m && a+b >= n+m) puts("Yes");
        else puts("No");
        
    }
    
    return 0;
}

