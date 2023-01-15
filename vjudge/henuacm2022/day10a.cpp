#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int lowbit(int x)
{
    return x & (-x);
}
int main()
{
    vector<PII> a;
    a.push_back({1, 1});
    a.push_back({2, 1});
    a.push_back({3, 0});
    for(int i=4;i<=1000;i++)
    {
        bool flag = true;
        for(auto j:a)
            if(i-j.first == lowbit(i-j.first) && j.second == 0)
            {
                a.push_back({i, 1});
                flag = false;
                break;
            }
        if(flag) a.push_back({i, 0});
    }
    int n;
    while (cin >> n)
    {
        n = a[n-1].second;
        if(n & 1) puts("Kiki");
        else puts("Cici");
    }
    
    return 0;
}
/*
1 1 0001
2 1 0010
3 0 0011
4 1 0100
5 1 0101
6 0 0110
7 1 0111
8 1 1000
9 0 1001
10 1    1010
11 1    1011
12 0    1100
13 1    1101
14 1    1110
15 0    1111
16 1   10000
*/