#include<map>
#include <iostream>
using namespace std;
int main()
{
    map<int, int> mp;
    mp.insert({1, 2});
    for(auto [k, v]:mp) cout << k << ' ' << v << endl;
    return 0;
}