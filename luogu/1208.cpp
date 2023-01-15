#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<PII> a;
    int num1, num2;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d", &num1, &num2);
        a.push_back({num1, num2});
    }
    sort(a.begin(), a.end());
    long long sum1 = 0, sum2 = 0;
    for(int i=0;i<m;i++)
    {
        if(sum1<n)
        {
            if(sum1+a[i].second>n) sum2 += a[i].first*(n-sum1);
            else sum2 += a[i].first*a[i].second;
            sum1 += a[i].second;
        }
        else break;
    }
    cout << sum2;
    return 0;
}