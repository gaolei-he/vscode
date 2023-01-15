#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5+10, P = 131;
char str1[N], str2[N];
ll h1[N], h2[N], num[N];
int sa[N], hei[N], tmp[N];
int length1, length2;
ll get(ll th[], int l, int r)
{
    return th[r] - th[l-1] * num[r-l+1];
}
int ans = 0;

bool check(int mid)
{
    vector<ll> tmp;
    for(int i=mid;i<=length1;i++)
    {
        ll tmp1 = get(h1, i-mid+1, i);
        tmp.push_back(tmp1);
    }
    sort(tmp.begin(), tmp.end());
    for(int i=mid;i<=length2;i++)
    {
        ll tmp1 = get(h2, i-mid+1, i);
        if(binary_search(tmp.begin(), tmp.end(), tmp1)) return true;
    }
    return false;
}


int main()
{
    str1[0] = str2[0] = '1';
    num[0] = 1;
    for(int i=1;i<=N-5;i++) num[i] = num[i-1] * P;
    scanf("%s", str1+1);
    scanf("%s", str2+1);
    length1 = strlen(str1) - 1;
    length2 = strlen(str2) - 1;

    for(int i=1;i<=length1 || i <=length2;i++)
    {
        if(i <= length1) h1[i] = h1[i-1] * P + str1[i];
        if(i <= length2) h2[i] = h2[i-1] * P + str2[i];
    }
    int l = 0, r = min(length1, length2);
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;

    return 0;
}
