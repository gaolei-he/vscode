#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt = 0;
        for(auto v : s) {
            if(v == c) {
                cnt += 1;
            }
        }
        return cnt * 1ll * (cnt + 1) / 2;
    }
};