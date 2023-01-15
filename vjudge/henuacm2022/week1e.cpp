#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int hui = 0;
    while(1)
    {
        ans += a;
        hui += a;
        a = hui / b;
        hui -= hui / b * b;
        if(a == 0 && hui < b) break;
    }
    cout << ans;
    return 0;
}

