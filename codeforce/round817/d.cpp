#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5+10;
char str[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", str + 1);
        vector<int> a;
        long long sum = 0;
        for(int i=1;str[i];i++)
        {
            if(str[i] == 'L') sum += i - 1;
            else if(str[i] == 'R') sum += n - i;
        }
        for(int i=1;i<=n/2;i++)
            if(str[i] == 'L') a.push_back(n - i - i + 1);

        for(int i=n/2+1;i<=n;i++)
            if(str[i] == 'R') a.push_back(i - 1 - n + i);
        
        a.push_back(2e9);
        
        sort(a.begin(), a.end(), greater<int>());
        // for(auto i:a) cout << i << ' ';
        // puts("");
        for(int i=1;i<=n;i++)
        {
            if(i >= a.size()) printf("%lld ", sum);
            else
            {
                sum += a[i];

                printf("%lld ", sum);
            }
        }
        puts("");
    }
    
    return 0;
}