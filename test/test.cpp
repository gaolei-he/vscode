#include <cstdlib>
#include <iostream>
using namespace std;
void hanoi(int n, char a, char b, char c)
{
    if(n == 1)
    {
        cout << 1 << ' ' << a << ' ' << c << endl;
        return;
    }
    hanoi(n-1, a, c, b);
    cout << n << ' ' << a << ' ' << c << endl;
    hanoi(n-1, b, a, c);
}
int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    string a = "1234";
    cout << atoi(a.c_str());
    return 0;
}