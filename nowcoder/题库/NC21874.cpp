#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> stk;
    string tmp;
    cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    while(tmp.size())
    {
        char c = tmp.back();
        tmp.pop_back();
        if(c == 'a') stk.push(c);
        else
        {
            if(!stk.size())
            {
                cout << "Bad";
                return 0;
            }
            stk.pop();
        }
    }
    if(stk.size()) cout << "Bad";
    else cout << "Good";
    return 0;
}