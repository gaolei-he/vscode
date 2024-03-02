#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            string& a = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string& b = words[j];
                if (b.starts_with(a) and b.ends_with(a)) res ++;
            }
        }
        return res;
    }
};