#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[8] = {6, 5, 14, 23, 2, 9, 87, 10};
    sort(a+1, a+7, greater<int>());
    for (int i = 0; i < 8; ++i)
        cout << a[i] << ",";
    return 0;
}