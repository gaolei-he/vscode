#include <iostream>
using namespace std;
int n, m;

int main()
{
    while (cin >> n)
    {
        int t = n, cnt = 0;
        int cnt1 = 0;
        cin >> m;
        int sum = 0;
        while (t--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            sum ^= abs(l-r) - 1;
        }
        if(sum) puts("I WIN!");
        else puts("BAD LUCK!");
    }
    
    return 0;
}
