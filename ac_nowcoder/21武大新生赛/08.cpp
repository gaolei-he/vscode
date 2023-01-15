#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = n / 3;
    if(n%3==2) ans *= (n / 3 + 1) * (n / 3 + 1);
    else if(n%3==1) ans *= (n / 3 + 1) * (n / 3);
    else ans *= ans * ans;
    cout << ans;
    return 0;
}