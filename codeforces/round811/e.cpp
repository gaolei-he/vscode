#include <iostream>
#include <set>
using namespace std;
const int N = 2e5+10;
int n;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool flag = true;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        set<int> s1, s2;
        for(int i=1;i<=n;i++)
        {
            s2 = s1;
            s1.clear();
            int tmp = a[i];
            while(tmp % 10)
            {
                if(s2.find(tmp) != s2.end()) continue;
                if(s1.find(tmp) != s1.end()) break;
                s1.insert(tmp);
                tmp += tmp % 10;
            }
            if(s1.empty())
            {
                bool flag = false;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");

    }
    
    return 0;
}