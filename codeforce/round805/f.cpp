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
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> a, b;
        int n;
        scanf("%d %d", &n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a.front() > b.front()) swap(a, b);
        int t;
        
        
    }
    return 0;
}