#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> a, b;
    bool check(int l, int r) {
        vector<int> tmp1 = a, tmp2 = b;
        if(!(tmp1[l] && tmp2[r])) return false;
        tmp1[l] --, tmp1[r] ++;
        tmp2[l] ++, tmp2[r] --;
        int cnt1 = 0, cnt2 = 0;
        for(auto i:tmp1) if(i) cnt1 ++;
        for(auto i:tmp2) if(i) cnt2 ++;
        return cnt1 == cnt2;
    }
    bool isItPossible(string word1, string word2) {
        a = vector<int>(26);
        b = vector<int>(26);
        for(auto i:word1) a[i-'a'] ++;
        for(auto i:word2) b[i-'a'] ++;
        bool res = false;
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(check(i, j)) return true;
        return false;
    }
};