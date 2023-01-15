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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }


int main()
{
    int t;
    int a, b, c;
    cin >> t;
    while (t--)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == b && b == c)
        {
            puts("-1");
            continue;
        }
        int n = gcd(abs(a-b), abs(b-c));
        vector<int> ans;
        for(int i=1;i<=n/i;i++)
        {
            if(n % i == 0)
            {
                ans.push_back(i);
                if(n/i != i) ans.push_back(n/i);
            }
        }
        sort(ans.begin(), ans.end());
        for(auto i:ans) cout << i << ' ';
        puts("");

    }
    
    return 0;
}