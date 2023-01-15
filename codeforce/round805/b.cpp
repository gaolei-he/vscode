#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10;
char str[N];
int main()
{
    int t;
    cin >> t;
    set<char> a;
    while (t--)
    {
        scanf("%s", str);
        int cnt = 0, length = strlen(str);
        int ans = 0;
        while(cnt < length)
        {
            while(a.size() < 3 && cnt < length) a.insert(str[cnt++]);
            while(*a.find(str[cnt]) >= 'a' && *a.find(str[cnt]) <= 'z' && cnt < length) cnt ++;
            ans ++;
            a.clear();
        }
        cout << ans << endl;
    }
    
    return 0;
}