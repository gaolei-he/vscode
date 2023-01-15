#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        cnt ++;
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            int tmp = x;
            if(!x) continue;
            else x = i + 1;
            if(x % 6 == 0 || x % 6 == 2 || x % 6 == 5) sum ^= tmp;
        }
        cout << "Case " << cnt << ": ";
        if(sum) puts("Alice");
        else puts("Bob");
        
    }
    
    return 0;
}