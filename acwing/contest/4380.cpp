#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], s1[N], s2[N];
int n, m, sum;
int main()
{
    cin >> n >> m;

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=m;i++) scanf("%d", &b[i]);

    sum = 0;
    for(int i=1;i<=n;i++) sum += a[i], s1[i] = sum;
    sum = 0;
    for(int i=1;i<=m;i++) sum += b[i], s2[i] = sum;
    
    int j = 1, k = 0;
    for(int i=1;i<=n;i++)
    {
        while(s1[i]>s2[j]) j++;
        if(s1[i]==s2[j]) k++;
        
    }
    cout << k;
    return 0;
}