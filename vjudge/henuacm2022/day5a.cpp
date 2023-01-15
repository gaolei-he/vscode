#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int N = 50 * 50 * 50 * 50 * 4 + 10;
short h[N];
short a[6];
int main()
{
    for(int i=1;i<=5;i++) scanf("%hd", &a[i]);
    for(int i=-50;i<=50;i++)
    {
        if(!i) continue;
        for(int j=-50;j<=50;j++)
        {
            if(!j) continue;
            int t = - a[1] * i * i * i - a[2] * j * j * j;
            t += 50 * 50 * 50 * 50 * 2;
            h[t] ++;
        }
    }
    long long ans = 0;
    for(int i=-50;i<=50;i++)
    {
        if(!i) continue;
        for(int j=-50;j<=50;j++)
        {
            if(!j) continue;
            for(int k=-50;k<=50;k++)
            {
                if(!k) continue;
                int t = a[3] * i * i * i + a[4] * j * j * j + a[5] * k * k * k;
                t += 50 * 50 * 50 * 50 * 2;
                if(t > 50 * 50 * 50 * 50 * 4 || t < 0) continue;
                else ans += h[t];
            }
        }
    }
    cout << ans << endl;
    return 0;
}