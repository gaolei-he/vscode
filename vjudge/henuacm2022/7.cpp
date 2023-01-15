#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5+10;
vector<int> shop, money;
int n, q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        shop.push_back(x);
    }
    sort(shop.begin(), shop.end());
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        money.push_back(x);
    }
    for(auto i:money)
    {
        cout << upper_bound(shop.begin(), shop.end(), i) - shop.begin() << endl;
    }
    
    return 0;
}