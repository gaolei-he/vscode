#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a, a1;
    set<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
        a1.push_back(x);
    }
    sort(a.begin(), a.end());
    
    for(int i=0;i<a.size();i++)
    {
        if(i == a.size() - 1) continue;
        if(a[i] == a[i + 1]) b.insert(a[i]);
    }
    // for(auto i:b) cout << i << ' ';
    // puts("");
    for(auto i:a1)
    {
        if(b.find(i) == b.end()) cout << i << ' ';
    }
    
    return 0;
}