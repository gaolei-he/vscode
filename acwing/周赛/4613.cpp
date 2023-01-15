#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 2e5+10;
char str[N];
bool st[N];
bool st1[N];
int main()
{
    int n;
    cin >> n;
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
    {
        vector<int> a;
        int x = i;
        while(!st[x] && x >= 0 && x < n)
        {
            st[x] = true;
            a.push_back(x);
            if(str[x] == '<') x --;
            else x ++;
        }
        if(x < 0 || x >= n || st1[x]) for(auto j:a) st1[j] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if(st1[i]) cnt ++;
    cout << cnt << endl;
    
    return 0;
}