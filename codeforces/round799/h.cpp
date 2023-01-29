#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0, l, r, ans1;
        int n;
        scanf("%d", &n);
        unordered_map<int, vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if(!q.count(x))
            {
                auto& v = q[x];
                v.push_back(1);
                v.push_back(i);
                v.push_back(i);

            }
            else
            {
                auto& v = q[x];
                int old = v[0], l1 = v[1], l2 = v[2];
                v.clear();
                if(old - (i - l2) + 2 > 0)
                {
                    
                    v.push_back(old - (i - l2) + 2);
                    v.push_back(l1);
                    v.push_back(i);
                }
                else
                {
                    v.push_back(1);
                    v.push_back(i);
                    v.push_back(i);
                }
            }
            auto& v = q[x];
            if(ans < v[0])
            {
                ans = v[0];
                l = v[1] + 1;
                r = v[2] + 1;
                ans1 = x;
            }
        }
        cout << ans1 << ' ' << l << ' ' << r << endl;

    }
    
    return 0;
}

