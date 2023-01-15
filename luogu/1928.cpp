#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string f()
{
    int n;
    char c;
    string s = "";
    while(cin>>c)
    {
        if(c=='[')
        {
            cin >> n;
            string s1 = f();
            while(n--) s += s1;
        }
        else if(c==']') return s;
        else s += c;
    }
    return s;
}

int main()
{
    cout << f();
    return 0;
}