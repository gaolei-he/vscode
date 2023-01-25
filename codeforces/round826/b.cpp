#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        if(n == 3) puts("-1");
        else if(n == 5) puts("5 4 1 2 3");
        else if(n & 1)
        {
            for(int i=n;i;i--)
            {
                if(i == (n + 1) / 2) printf("%d ", i + 1);
                else if(i == (n + 1) / 2 + 1) printf("%d ", i - 1);
                else printf("%d ", i);
            }
            puts("");
        }
        else
        {
            for(int i=n;i;i--) printf("%d ", i);
            puts("");
        }
    }
    return 0;
}
