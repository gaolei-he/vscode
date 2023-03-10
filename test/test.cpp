#include <iostream>
using namespace std;
int idx[2010];
int main()
{
    int n; cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        for (int j = x + 1; j < 2010; j++)
        {
            ans += idx[j];
        }
        idx[x] ++;
    }
    cout << ans << endl;
    return 0;
}