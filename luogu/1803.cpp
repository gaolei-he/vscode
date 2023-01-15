#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class myvector
{
public:
    T * a = new T[2];
    T operator[](int k){return *(a+k);}
    int cnt = 0;
    int size() {return cnt;}
    void push_back(T k)
    {
        if((cnt|0) == cnt)
        {
            T *tmp = new T[(cnt+1)*2];
            memcpy(tmp, a, sizeof(T[(cnt+1)*2]));
            delete []a;
            a = tmp;
        }
        *(a + cnt ++) = k;
    }
    void pop_back() { cnt--; }

    void clear() { cnt = 0;}
    T *begin(){return a;}
    T *end(){return a+cnt;}
    void erase(T *tmp1, T *tmp2)
    {
        cnt = tmp1 - a;
    }
};

typedef pair<int, int> PII;
int main()
{
    int n;
    cin >> n;
    myvector<PII> a;
    for(int i=0;i<n;i++)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        a.push_back({num2, num1});
    }
    sort(a.begin(), a.end());
    int now = -1, ans = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i].second>=now)
        {
            ans ++;
            now = a[i].first;
        }
    }
    cout << ans;
    return 0;
}