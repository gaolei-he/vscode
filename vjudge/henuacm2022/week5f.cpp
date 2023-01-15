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
    while (t--)
    {
        int x;
        cin >> x;
        int ans;
        if(x <= 2) ans = 1;
        else if(x <= 10) ans = 2;
        else if(x <= 18) ans = 3;
        else if(x <= 36) ans = 4;
        else if(x <= 54) ans = 5;
        else if(x <= 86) ans = 6;
        else if(x <= 118) ans = 7;
        cout << ans << endl;
    }
    
    return 0;
}