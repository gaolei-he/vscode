#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;


int main()
{
    while(1)
    {
        string s;
        getline(cin, s);
        if(s == "#") break;
        string s1;
        istringstream tmp(s);
        set<string> ans;
        while(tmp >> s1) ans.insert(s1);
        cout << ans.size() << endl;
    }

    return 0;
}