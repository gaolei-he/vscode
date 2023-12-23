#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check1(string &s, int st, int cnt) {
        for(int i = st; i < s.size(); i ++) {
            if (s[i] == '1') cnt --;
            if (cnt == 0) return i - st + 1;
        }
        return 1000;
    }
    bool check2(string &s, int st, int len, int k) {
        for(int i = st; st + len > i and i < s.size(); i ++) {
            if (s[i] == '1') k --;
            if (k == 0) return true;
        }
        return false;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int len = 1000;
        for(int i = 0; i < s.size(); i++) {
            len = min(len, check1(s, i, k));
        }
        set<string> res;
        for(int i = 0; i < s.size(); i++) {
            if (check2(s, i, len, k)) res.insert(s.substr(i, len));
        }
        if(res.size()) return *res.begin();
        return "";
    }
};