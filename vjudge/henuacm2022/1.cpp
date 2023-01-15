#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N = 3e3+10;
class mypair
{
public:
    string first;
    int second;
    int third;
    bool operator<=(mypair tmp)
    {
        return second <= tmp.second;
    }
    bool operator>(mypair tmp)
    {
        if(second != tmp.second) return second > tmp.second;
        else return third < tmp.third;
    }
    
};
mypair a[N], tmp[N], b[N];
void merge_sort(mypair a[], int l, int r)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] > a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l, j=0;i<=r;i++, j++) a[i] = tmp[j];
}
int main()
{
    int n;
    while (cin >> n)
    {
        unordered_map<string, int> tmp1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            a[i].third = i;
            tmp1[a[i].first] = a[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].first >> b[i].second;
        }
        merge_sort(a, 0, n-1);
        bool flag1 = true, flag2 = true;
        for (int i = 0; i < n; i++)
        {
            if(a[i].second != b[i].second) flag1 = false;
            else if(a[i].first != b[i].first) flag2 = false;
            tmp1[b[i].first] = -1;
        }
        if(flag1 && flag2) cout << "Right\n";
        else
        {
            bool flag = true;
            for(auto i:tmp1) if(i.second != -1 || (!flag1)){ cout << "Error\n"; flag = false; break; }
            if(flag) cout << "Not Stable\n";
            for (int i = 0; i < n; i++)
            {
                cout << a[i].first << ' ' << a[i].second << endl;
            }
            
        }

    }
    
    return 0;

}