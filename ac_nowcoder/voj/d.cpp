#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> a;
const double eps = 1e-2;
int n, m;
vector<pair<double, double> > ans;
double g(double t){ return t * t;}
bool f(pii a, pii b, pii c, pii d)
{
    double xg = (a.first + b.first + c.first + d.first) / 4.0;
    double yg = (a.second + b.second + c.second + d.second) / 4.0;
    double dis = g(a.first - xg) + g(a.second - yg);
    double tmp = g(b.first-xg) + g(b.second-yg);
    if(fabs(tmp-dis) > eps) return false;
    tmp = g(c.first - xg) + g(c.second - yg);
    if(fabs(tmp - dis) > eps) return false;
    tmp = g(d.first - xg) + g(d.second - yg);
    if(fabs(tmp - dis) > eps) return false;
    ans.push_back({xg, yg});

    return false;

}
bool cmp(pair<double, double> a, pair<double, double> b)
{
    if(fabs(a.first-b.first) < eps && fabs(a.second - b.second) < eps) return true;
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    
    
    if(n != 4 && n != 8) puts("No");
    else
    {
        
        for(int i=0;i<a.size()-3;i++)
        for(int j=i+1;j<a.size()-2;j++)
        for(int k=j+1;k<a.size()-1;k++)
        for(int l=k+1;l<a.size();l++)
            f(a[i], a[j], a[k], a[l]);
        sort(ans.begin(), ans.end());
        int t = 0;
        n >>= 2;
        while(n) {t ++; n >>= 2;}
        if(t == 1 && ans.size())
        {
            puts("Yes");
            return 0;
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if(i == ans.size() - 1) continue;
            if(cmp(ans[i], ans[i+1]))
            {
                puts("Yes");
                return 0;
            }
        }
        
        
    }
    puts("No");
    return 0;
}