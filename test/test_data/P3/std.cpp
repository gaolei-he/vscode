#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int ans = 0;
    while(n --)
    {
        bool flag = true;
        int x;
        char c;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x;
        if(x > 255) flag = false;
        if(flag) ans ++;
    }
    cout << ans << endl;
}