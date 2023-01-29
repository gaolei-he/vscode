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
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
const int N = 30, mod = 1e9 + 7;
int n, q;
char tmp[N];
vector<char> vec;

void merge_sort(vector<char>& vec, int l, int r)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(vec, l, mid);
    merge_sort(vec, mid+1, r);
    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        char a = vec[i], b = vec[j];
        cout << "? " << a << ' ' << b << endl;
        char res; cin >> res;
        if(res == '<') tmp[k++] = vec[i++];
        else tmp[k++] = vec[j++];
    }
    while(i <= mid) tmp[k++] = vec[i++];
    while(j <= r) tmp[k++] = vec[j++];
    for(int i=l, j = 0;i<=r;i++, j++) vec[i] = tmp[j];
}
char ask(char a, char b)
{
    cout << "? " << a << ' ' << b << endl;
    char res; cin >> res;
    return res;
}
void f()
{
    char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
    if(ask(a, b) == '>') swap(a, b);
    if(ask(c, d) == '>') swap(c, d);
    if(ask(a, c) == '>')
    {
        swap(a, c);
        swap(b, d);
    }
    if(ask(c, e) == '<')
    {
        if(ask(d, e) == '>') swap(d, e);
        if(ask(b, d) == '<')
            {if(ask(b, c) == '<')
                cout << "! " << a << b << c << d << e << endl;
            else
                cout << "! " << a << c << b << d << e << endl;}
        else
            {if(ask(b, e) == '>')
                cout << "! " << a << c << d << e << b << endl;
            else
                cout << "! " << a << c << d << b << e << endl;}
    }
    else
    {
        if(ask(a, e) == '>') swap(a, e);
            {if(ask(b, c) == '<')
                cout << "! " << a << e << b << c << d << endl;
            else if(ask(b, d) == '<')
                cout << "! " << a << e << c << b << d << endl;
            else
                cout << "! " << a << e << c << d << b << endl;}
    }
}
void solve()
{
    cin >> n >> q;
    vec.push_back('#');
    rep(i, 0, n-1) vec.push_back('A'+i);
    // sort(vec.begin(), vec.end(), [](char a, char b){
    //     cout << "? " << a << ' ' << b << endl;
    //     char ans; cin >> ans;
    //     if(ans == '<') return true;
    //     else return false;
    // });
    if(q == 7) f();
    else {merge_sort(vec, 1, n);
    cout << "! ";
    rep(i, 1, n) cout << vec[i];
    cout << endl;}
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