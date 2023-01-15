#include <iostream>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); i++)
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) return false;
        if(sentence.front() != sentence.back()) return false;
        return true;
    }
};
int main()
{

    return 0;
}