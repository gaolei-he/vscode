#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> S;
        for(auto x : arr2) {
            string s = to_string(x);
            while(!s.empty()) {
                S.insert(s);
                s.pop_back();
            }
        }
        int res = 0;
        for (auto x : arr1) {
            string s = to_string(x);
            while(!s.empty()) {
                if (S.count(s)) res = max(res, (int)s.size());
                s.pop_back();
            }
        }
        return res;
    }
};