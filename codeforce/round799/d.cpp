#include <iostream>
using namespace std;
inline bool check(int tim)
{
    int h = tim / 60;
    int m = tim % 60;
    if(h / 10 == m % 10 && h % 10 == m / 10) return true;
    else return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hour, minute;
        scanf("%d:%d", &hour, &minute);
        int per;
        int total = hour * 60 + minute;
        scanf("%d", &per);
        int tmp = total;
        int ans = 0;
        do
        {
            if(check(tmp)) ans ++;
            tmp += per;
            while(tmp >= 1440) tmp -= 1440;
        } while (tmp != total);
        
        cout << ans << endl;

    }
    
    return 0;
}