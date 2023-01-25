#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10;
char s[N];
int p;
int alpha[26];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(alpha, 0, sizeof(alpha));
        scanf("%s %d", s, &p);
        for (int i = 0; s[i]; i++)
            alpha[s[i]-'a'] ++;
        int sum = 0;
        for(int i = 0; i < 26; i++) sum += alpha[i] * (i + 1);
        int cnt = 25;
        while (sum > p && cnt >= 0)
        {
            int tmp = sum - p;
            if(alpha[cnt] * (cnt+1) >= tmp)
            {
                alpha[cnt] -= tmp / (cnt+1);
                if(tmp % (cnt + 1)) alpha[cnt] --;
                tmp = 0;
            }
            else
            {
                tmp -= alpha[cnt] * (cnt + 1);
                alpha[cnt] = 0;
            }
            cnt --;
            sum = tmp + p;
        }
        for(int i=0;s[i];i++)
        {
            alpha[s[i]-'a'] --;
            if(alpha[s[i]-'a'] >= 0) putchar(s[i]);
        }
        puts("");
    }
    return 0;
}