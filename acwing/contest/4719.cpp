#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    set<string> lib;
    cin >> n;
    while(n --)
    {
        string a, b;
        cin >> a >> b;
        lib.insert(a + ' ' + b);
    }
    cout << lib.size() << endl;
    return 0;
}