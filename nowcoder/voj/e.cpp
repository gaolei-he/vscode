#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int a[30], n;
vector<ll> ans;
vector<int> tmp;
const int P = 131;
ll p[30];
ll g()
{
    ll res = 0;
    for(int i=1;i<=tmp.size();i++) res += p[i] * tmp[i-1];
    return res;
}
void f(int pos, int i)
{
    if(!i)
    {
        int t = ans.size();
        ans.push_back(g());

        return;
    }
    else if (pos > n) return;    
    for(int j=pos;j<=n;j++)
    {
        tmp.push_back(a[j]);
        f(j + 1, i - 1);
        tmp.pop_back();
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i=0;i<a.size();i++) if(a[i] != b[i]) return a[i] < b[i];
    return true;
}

int main()
{
    
    cin >> n;
    p[0] = 1;
    for(int i=1;i<=25;i++) p[i] = p[i - 1] * P;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    for(int i=1;i<n;i++)
    {
        f(1, i);
        tmp.clear();
    }
    sort(ans.begin(), ans.end());
    int sum = 0;
    // for(auto i:ans) cout << i << ' ';
    for (int i = 0; i < ans.size(); i++)
    {
        if(i == ans.size() - 1) continue;
        if(ans[i] == ans[i + 1])
        {
            ll tmp = ans[i];
            while(tmp == ans[i]) i++;
            sum ++;
            i --;
        }
    }
    cout << sum << endl;
    
    return 0;
}