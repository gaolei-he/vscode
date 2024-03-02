// date Sun Nov 19 01:42:10 PM CST 2023
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n; double rate; cin >> n >> rate;
    vector<int> vec(n + 1);
    for(auto &x : vec) cin >> x;
    double ans = 0;
    for(int i=0;i<=n;i++)
    {
        ans += vec[i] * pow(1+rate, -i);
    }
    cout << ans << endl;
    return 0;
}