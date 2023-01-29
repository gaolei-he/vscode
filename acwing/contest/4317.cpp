#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, num;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &num);
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    int length1 = a.size();
    a.erase(unique(a.begin(), a.end()), a.end());
    printf("%ld", 2*a.size()-length1);
    return 0;
}