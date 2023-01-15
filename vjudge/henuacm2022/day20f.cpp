#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main()
{
    int n;
    while (cin>>n)
    {
        int res = n;
        if(!n) break;
        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                res = res/i*(i-1);
                while(n%i==0) n /= i;
            }
        }
        if(n > 1) res = res / n * (n - 1);
        cout << res << endl;
    }
    
    return 0;
}