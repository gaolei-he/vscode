#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, N;
    cin >> n >> N;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;

    int ans = 0;
    for(auto x : vec) ans += N - x;
    cout << ans << endl;
    return 0;
}