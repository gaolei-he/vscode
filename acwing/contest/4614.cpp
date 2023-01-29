#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5+10;
int n, m, q;
int w[20];

int read()
{
    char str[20];
    scanf("%s", str);
    int ans = 0, R = 1;
    for (int i = 0; str[i]; i++)
    {
        if(str[i] == '1') ans += R;
        R *= 2;
    }
    return ans;
}
bool cmp(int x, int k, int pos)
{
    int res = 0;
    int tmp = (x ^ pos);
    // cout << '#' << tmp << endl;
    for (int i = 0; i < n; i++)
    {
        if(((tmp >> i)&1) == 0) res += w[i];
        if(res > k) return false;
    }
    if(res <= k) return true;
    else return false;
    
}
int main()
{
    cin >> n >> m >> q;
    for(int i=0;i<n;i++) scanf("%d", &w[i]);
    vector<pii> a;
    map<int, int> tmp;
    while (m--)
    {
        int x = read();
        tmp[x] ++;
    }
    for(auto i:tmp) a.push_back({i.first, i.second});

    while (q--)
    {
        int x = read();
        int k;
        scanf("%d", &k);
        int ans = 0;
        for(auto i:a) if(cmp(i.first, k, x)) ans += i.second;
        printf("%d\n", ans);
    }
    
    return 0;
}