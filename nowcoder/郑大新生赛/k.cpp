#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#define int long long
using namespace std;
int f[1000008];
bool isPrime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
bool st[1000008];
signed main()
{
    vector<int> pr;
    int cnt = 0;
    for(int i=2;i<=1e6+1;i++)
    {
        if(!st[i])
        {
            pr.push_back(i);
            cnt ++;
        }
        for(int j=0;pr[j] <= (1e6+1)/i;j ++)
        {
            st[pr[j]*i] = true;
            if(i % pr[j] == 0) break;
        }
    }
    for(int i=1;i<=1e6+1;i++)
    {
        if(binary_search(pr.begin(), pr.end(), i)) f[i] = 0;
        else
        {
            for(auto j:pr)
            {
                if(j >= i) break;
                if(i%j==0)
                {
                    if(f[i])
                    {
                        f[i] = 0;
                        break;
                    }
                    if(i/j == j) f[i] = 1;
                    else
                    {
                        f[i] = 0;
                        break;
                    }

                }
            }
        }
    }
    for(int i=1;i<=1e6;i++) f[i] += f[i-1];
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        scanf("%lld %lld", &l, &r);
        l = ceil(sqrt(l));
        r = floor(sqrt(r));
        cout << l << ' ' << r << endl;
        cout << f[r] <<  ' ' << f[l - 1] << endl;
        printf("#%lld\n", f[r]-f[l-1]);
    }
    

    return 0;
}