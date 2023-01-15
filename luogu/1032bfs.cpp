#include <queue>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, string> lib;
bool st[20];
int main()
{
    string a, b;
    cin >> a >> b;
    string t1, t2;
    while(cin >> t1)
    {
        cin >> t2;
        lib.insert({t1, t2});
        
    }
    return 0;
}