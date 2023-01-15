#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, b;
vector<int> a;

void quick_sort(int l, int r)
{
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l+r)>>1];
    while (i<j)
    {
        do i++;while(a[i] > x);
        do j--;while(a[j] < x);
        if(i<j) swap(a[i], a[j]);
    }
    quick_sort(l, j), quick_sort(j+1, r);
    
}

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    for(int i=0;i<a.size();i++)
    {
        sum += a[i];
        if(sum >= b)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    
    return 0;
}