#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    using ull = unsigned long long;
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<int> st;
        for(auto &s : forbidden)
        {
            ull h = 0;
            for(auto c : s) h = h * 131 + c;
            st.insert(h);
        }
        vector<ull> p(word.size() + 1);
        vector<ull> h(word.size() + 1);
        p[0] = 1;
        for(int i = 1; i <= word.size(); i ++) p[i] = p[i-1] * 131, h[i] = h[i-1] * 131 + word[i-1];
        int res = 0;
        int lst = -1;
        for (int i = 0; i < word.size(); i ++)
        {
            int tmplst = lst;
            for(int j = 1; j <= 10 and i - j + 1 >= 0; j ++)
            {
                int r = i, l = i - j + 1;
                if(st.count(h[r+1] - h[l] * p[r-l+1]))
                {
                    res = max(res, i - lst - 1);
                    tmplst = max(tmplst, l);
                }
            }
            lst = tmplst;
        }
        res = max((int)word.size() - lst - 1, res);
        return res;
    }
};
int main()
{
    Solution so;
    freopen("/home/mechrevo/Documents/vscode/leetcode/test.txt", "r", stdin);
    vector<string> forbidden;
    string str;
    cin >> str;
    string s;
    char c;
    while(cin >> c)
    {
        if(c == '"') continue;
        else if(c == ',')
        {
            forbidden.push_back(s);
            s.clear();
        }
        else s.push_back(c);
    }

    std::cout << so.longestValidSubstring(str, forbidden);
}