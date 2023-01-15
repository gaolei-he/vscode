#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    rep(i, 0, n-1)
    {
        int x; cin >> x;
        switch (i%3)
        {
        case 0:a+=x; break;
        case 1:b+=x; break;
        case 2:c+=x; break;
        default:
            break;
        }
    }
    if(a == max(a, max(b, c))) cout << "chest";
    else if(b == max(a, max(b, c))) cout << "biceps";
    else cout << "back";

    return 0;
}