#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        map<int, int> mp;
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        long long res = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0;i<k;i++) {
            res += items[i][0];
            mp[items[i][1]]++;
            if(mp[items[i][1]] > 1) pq.push(items[i][0]);
        }
        long long tmp = mp.size();
        ans = res + tmp * tmp;
        for (int i=k;i<items.size();i++) {
            if(mp.count(items[i][1])) continue;
            else if(pq.empty()) break;
            res -= pq.top();
            // cerr << "#" << pq.top() << endl;
            pq.pop();
            mp[items[i][1]]++;
            res += items[i][0];
            // cout << "#" << res << endl;
            long long tmp = mp.size();
            ans = max(ans, res + tmp * tmp);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> items = {{7,1},{4,1},{3,2},{10,1}};
    return 0;
}