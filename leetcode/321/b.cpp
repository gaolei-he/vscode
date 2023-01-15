#include <iostream>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        for(;i<s.size() && j < t.size();i++) {
            if(s[i] == t[j]) j++;
        }
        return t.size() - j;
    }
};
int main()
{
    Solution so = Solution();
    cout << so.appendCharacters("z", "abcde");
    return 0;
}