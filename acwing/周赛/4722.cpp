#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> a;
    for(int i=1;i<=500;i++) a.insert((1+i)*i/2);
    if(a.find(n) != a.end()) cout << "YES";
    else cout << "NO";
    return 0;
}