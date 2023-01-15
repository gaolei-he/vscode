#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e4+10;
vector<int> a, b, d;
int sear1(int x)
{
    int l = 0, r = a.size()-1;
    while (l<r)
    {
        int mid = l + r >> 1;
        if(a[mid]>=x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int sear2(int x)
{
    int l = 0, r = a.size()-1;
    while(l<r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid]<=x) l = mid;
        else r = mid - 1;
    }
    return l;
}

bool sear3(int x)
{
    int l = 0, r = d.size() - 1;
    for (auto i:d)
    {
        if(i==x) return false;
    }
    return true;
    
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        b = a;
        sort(a.begin(), a.end());

        for(auto item:b)
        {
            if(sear1(item)==sear2(item)) printf("%d ", item);
            else
            {
                if(sear3(item)) printf("%d ", item);
                d.push_back(item);
            }
        }
        cout << '\n';
        vector<int> c;
        b = a = d = c;
    }
    return 0;
}