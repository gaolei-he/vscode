#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void haxi(unsigned long long *a, unsigned long long *b, unsigned long long *p, string s, int n)
{
    unsigned long long hx = 131, H = 0, h = 0;
    p[0] = 1;
    a[0] = b[0] = 0;
    s = " " + s;
    for (int i = 1; i <= n; i++)
    {
        H = H * hx + static_cast<unsigned long long>(s[i]);
        a[i] = H;
        h = h * hx + static_cast<unsigned long long>(s[n + 1 - i]);
        b[i] = h;
            p[i] = p[i - 1] * hx;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    unsigned long long a[n+1], b[n+1], p[n+1];
    haxi(a, b, p, s, n);
    //	for(int i = 0; i < n; i ++){
    //		cout << "i = " << i << ", a[i] = " << a[i] << ", b[i] = " << b[i] << endl;
    //	}
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        
            unsigned long long bb = a[r] - a[l - 1] * p[r - l + 1];
            unsigned long long pp = b[n - l + 1] - b[n - r] * p[r - l + 1];
            // cout << "l = " << l << ", r = " << r << ", pp = " << pp << ", bb = " << bb << endl;
            // cerr << bb << ' ' << pp << endl;
            if (pp == bb)
            {
                cout << "Budada" << endl;
            }
            else if ((r - l + 1) % 2 == 0)
            {
                cout << "Budada" << endl;
            }
            else
            {
                cout << "Putata" << endl;
            }
    }
    return 0;
}