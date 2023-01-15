#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;
int main()
{
    int x = 100, y = 200, z = 300;
    cout << [](double a, double b){return a + b;} (1, 2.3) << endl;
    auto ff = [=,&y, &z](int n)
    {
        cout << x << endl;
        y ++, z ++;
        return n * n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;
    cout << sizeof(decltype(ff)) << endl;
    int a[4] = {4, 2, 11, 33};
    sort(a, a+4, [](int x, int y){return x % 10 < y % 10;});
    for_each(a, a+4, [](int x){cout << x << " ";});

    function<int(int)> fib = [&fib](int n) { return n <= 2 ? 1 : fib(n-1) + fib(n-2);};
    cout << fib(8) << endl;
    return 0;
}