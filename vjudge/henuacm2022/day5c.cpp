#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int P = 131, N = 1e6+10, M = 1e4+10;
typedef unsigned long long ll;
char str1[N];
ll h[N], num[N];

ll get(int l, int r)
{
    return h[r] - h[l-1] * num[r-l+1];
}

int main()
{
    long long n, tmp;
    cin >> n >> tmp;
    scanf("%s", str1+1);
    str1[0] = '1';
    num[0] = 1;
    for(int i=1;i<=1e6+5;i++) num[i] = num[i-1] * P;


    ll l1 = strlen(str1) - 1;
    for (int i=1;i<=l1;i++) h[i] = h[i-1] * P + str1[i];
    vector<int> ans;
    int cnt = 0;
    for (int i=1;i<=l1;i++)
        if(i+n-1 > l1) break;
        else ans.push_back(get(i, i+n-1));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    return 0;
}