#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<bool> vec;
    for(int i=0;i<100;i++) vec.push_back(true);
    cout << sizeof(vec);
    return 0;
}