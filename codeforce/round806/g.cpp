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
const int N = 1e5+10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        int sum = 0;
        for(int i=1;i<=n;i++) sum += a[i];
        cout << sum << endl;
    }
    
    return 0;
}

