#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubstringPresent(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        for(int i=0;i<s.size()-1;i++) {
            if(tmp.find(s.substr(i, 2)) != string::npos) {
                return true;
            }
        }
        return false;
    }
};