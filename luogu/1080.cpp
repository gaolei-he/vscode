#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct A
{
    int l, r, shang;
    /* data */
};
bool rule(A s1, A s2)
{
    return s1.shang < s2.shang;
}

vector<int> mymax(const vector<int> &a, const vector<int> &b)
{
    if(a.size()==b.size())
    {
        for(int i=a.size()-1;i>=0;i++) if(a[i]!=b[i]) return a[i]>b[i]?a:b;
        return a;
    }
    else return a.size()>b.size()?a:b;
}

vector<int> divi(vector<int> a, int x)
{
    vector<int> ans;
    int r = 0;
    for(int i=a.size()-1;i>=0;i--)
    {
        r = a[i] + r * 10;
        ans.push_back(r/x);
        r %= x;
    }

    reverse(ans.begin(), ans.end());
    while(ans.size()>1&&ans.back()==0) ans.pop_back();
    return ans;

}

vector<int> mul(vector<int> a, int b)
{
    vector<int> ans;
    int r = 0;
    for(int i=0;i<a.size();i++)
    {
        r += a[i] * b;
        ans.push_back(r%10);
        r /= 10;
    }
    while(r)
    {
        ans.push_back(r%10);
        r /= 10;
    }
    while(ans.size()>1&&ans.back()==0) ans.pop_back();
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int kl, kr;
    cin >> kl >> kr;
    A a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &a[i].l, &a[i].r);
        a[i].shang = a[i].l*a[i].r;
    }
    sort(a, a+n, rule);
    
    vector<int> ji, ma;
    while(kl)
    {
        ji.push_back(kl%10);
        kl /= 10;
    }
    for(int i=0;i<n;i++)
    {
        ma = mymax(divi(ji, a[i].r), ma);
        ji = mul(ji, a[i].l);
    }
    for(int i=ma.size()-1;i>=0;i--) cout << ma[i];
    return 0;
}