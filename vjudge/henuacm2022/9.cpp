#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
long long n;
int m;
vector<int> mymin(vector<int> a, vector<int> b)
{
    if(a.size() == 0) return b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] < b[i]) return a;
        else if(a[i] > b[i]) return b;
    }
    return a;
}
bool st[12];
int N;
vector<int> ans;
void dfs(int k)
{
    if(k == m)
    {
        vector<int> tmp;
        for(int i=0;i<a.size();i++)
        {
            if(!st[i]) tmp.push_back(a[i]);
        }
        ans = mymin(ans, tmp);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            dfs(k + 1);
            st[i] = false;
        }
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        a.clear();
        cin >> n >> m;
        while (n)
        {
            a.push_back(n%10);
            n /= 10;
        }
        N = a.size();
        reverse(a.begin(), a.end());
        dfs(0);
        for(auto i:ans) cout << i;
        puts("");
    }
    
        
    return 0;
}