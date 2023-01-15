#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long res = 0;
        long long now = skill.front() + skill.back();
        for(int i=0, j=skill.size()-1;i<j;i++,j--) {
            if(skill[i] + skill[j] != now) return -1;
            res += skill[i] * skill[j];
        }
        return res;
    }
};
int main()
{

    return 0;
}