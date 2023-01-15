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
inline bool isHui(int k)
{
    vector<int> tmp;
    tmp.push_back(1);
    while(k)
    {
        tmp.push_back(k%10);
        k /= 10;
    }
    for(int i=1;i<=tmp.size()/2;i++)
    {
        if(tmp[i] != tmp[tmp.size()-i]) return false;
    }
    return true;
}
int main()
{
    int cnt = 0;
    for(int i=2;i<=10000000;i++)
    {
        if(isHui(i))
        {
            cout << i << ", ";
            cnt ++;
            if(cnt % 20 == 0) puts("");
        }
    }
    cout << cnt;
    return 0;
}