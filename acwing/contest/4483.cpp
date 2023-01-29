#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int j = 1, i = 0;
    int cnt = 0;
    a.push_back(1e9+10);
    while (true)
    {
        while(a[i]==a[j]) j++;
        if(j>=n) break;
        if(a[j] - a[i] <= k) cnt ++;
        i ++;
    }
    cout << n - cnt;
    return 0;
}