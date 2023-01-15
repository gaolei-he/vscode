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
const int N = 2e5+10;
int ans[N];
bool st[100000];
int main()
{
    int cnt = 0;
    int n = 100000;
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) ans[cnt++] = i;
        for(int j=0;ans[j] <= n/i;j++)
        {
            st[ans[j]*i] = true;
            if(i % ans[j] == 0) break;
        }
    }


    while(cin >> n)
    {
        bool flag = false;
        for (int i = 0; i < 9591; i++)
        {
            
            for (int j = i; j < 9592; j++)
            {
                if(binary_search(ans, ans+9592, n-ans[i]-ans[j]))
                {
                    cout << ans[i] << ' ' << ans[j] << ' ' << n - ans[i] - ans[j] << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }

    
    
    return 0;
}