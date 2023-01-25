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
        string s;
        cin >> s;
        for(auto &i:s) if(i > 'a') i -= 32;
        if(s == "YES") puts("YES");
        else puts("NO");
    }
    
    return 0;
}