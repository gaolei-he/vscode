#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> ans;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        for(int i=2;i<=x/i;i++)
            while(x%i == 0) {ans[i] ++; x /= i;}
        if(x > 1) ans[x] ++;
        //for(auto i:ans) cout << i.first << endl;
    }
    int res = 1;
    for(auto i:ans) res *= i.second + 1;
    cout << res % 10 << endl;
    return 0;
}