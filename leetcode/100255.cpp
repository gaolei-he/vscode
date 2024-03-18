#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDeletions(string word, int k) {
        std::map<char, int> mp;
        for (auto c : word) {
            mp[c] += 1;
        }
        std::vector<int> vec;
        for (auto [t, v] : mp) {
            vec.emplace_back(v);
        }
        std::sort(vec.begin(), vec.end());
        std::vector<int> sm(vec.size() + 2);
        for (int i = 1; i <= vec.size(); i++) {
            sm[i] = sm[i - 1] + vec[i - 1];
        }

        int res = 10000000;
        auto calc = [&](int l, int r) {
            
            l++, r++;
            int val = sm[l - 1];
            val += sm[vec.size()] - sm[r] - (vec.size() - r) * (vec[l - 1] + k);
            // std::cerr << l << " " << r << " " << sm.size() << " " << vec.size() << " " <<  (vec[l]) << "\n";
            res = std::min(res, val);
        };
        // for(auto x : vec)  std::cerr << x << " ";
        for (int l = 0, r = 0; l < vec.size(); l++) {
            while (r + 1 < vec.size() and vec[r + 1] - vec[l] <= k) {
                r += 1;
            }
            calc(l, r);
        }
        return res;
    }
};

int main()
{
    Solution so;
    string s;
    int v;
    std::cin >> s >> v;
    std::cout << so.minimumDeletions(s, v);
    return 0;
}