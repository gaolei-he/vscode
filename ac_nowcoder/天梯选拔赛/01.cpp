#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    if(!k&1) n--;
    cout << ((int) pow(2, n))%p;
    return 0;
} // namespace std;
/*
0 1             1, 2
0 1 2 3         1, 2, 2, 4
0 1 2 3 4 5 6 7 1, 2, 2, 4, 
*/