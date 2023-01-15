#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 100 + 4e5, mod = 1e9 + 7;
int ne[N], ne1[N];
char str[N], tmp[N];
int length;

bool flag = false;
void solve()
{
    length = 0;
    memset(ne1, 0, sizeof(ne1));
    memset(str, 0, sizeof(str));
    if(flag) return;
    
    if(tmp[0] == 0) scanf("%s", tmp);
    str[0] = '$', str[1] = '#';
    int length1 = 2;
    for(int i=0;tmp[i];i++)
    {
        str[length1++] = tmp[i];
        str[length1++] = '#';
    }
    str[length1++] = '^';
    int mr = 0, ml = 0;
    for(int i=1;str[i]!='^'; i++)
    {
        if(i < mr) ne[i] = min(ne[ml*2-i], mr - i);
        else ne[i] = 1;
        while(str[i+ne[i]] == str[i-ne[i]]) ne[i] ++;
        if(ne[i] + i > mr)
        {
            mr = ne[i] + i;
            ml = i;
        }
    }
    for(int i=1;i<=length1;i++)
        if(str[i] == '#' && ne[i] != 1)
            ne1[i-ne[i]+1] = i + ne[i] - 1;

    for(int i=1;i<=length1;i++)
    {
        if(ne1[i]) i = ne1[i] - 1;
        else if(str[i] >= 'a' && str[i] <= 'z') tmp[length++] = str[i];
    }
    tmp[length] = 0;

    function<bool(void)> check = [&](){
        for(int i=1;i<=length1;i++)
        {
            if(str[i] == '#' && ne[i] >= 2) return false;
        }
        flag = true;
        return true;
    };
    function<void(void)> print = [&](){
        for(int i=1;i<=length1;i++)
        {
            if(ne1[i]) i = ne1[i] - 1;
            else if(str[i] >= 'a' && str[i] <= 'z') cout << str[i];
        }
        cout << endl;
    };
    // print();
    if(check()) print(), flag = true;
    else solve();


}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}