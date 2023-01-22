#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int a1 = 0, a0 = 0;
        int n1 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1') n1++;
            if(s[i] != target[i])
            {
                if(s[i] == '1') a1 ++;
                else a0 ++;
            }
        }
        if(a1 && a0) return true;
        else if(a0 && n1) return true;
        else if(a1 && n1 > a1) return true;
        else if(a0 == 0 && a1 == 0) return true;
        return false;
    }
};