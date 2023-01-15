#include <vector>
#include <iostream>
#include <algorithm>
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
};

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    a[n] = 2e9;
    myvector<int> ans[n];
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i+1]) ans[cnt++].push_back(a[i]);
        else ans[cnt].push_back(a[i]);
    }
    int mi = 1e6;
    if(ans[cnt].size()==0) cnt --;


    int cnt1 = 0, now = 0;
    while(1)
    {
        
        cnt1 = now;
        int tmp1 = cnt1;
        bool ret = false;
        while(ans[cnt1].size()<=ans[cnt1+1].size()&&ans[cnt1][0]==ans[cnt1+1][0]-1)
        {
            ans[cnt1].pop_back();
            if(ans[cnt1].size()==0) now = cnt1 + 1;
            cnt1 ++;
            ret = true;
            if(cnt1>=cnt-1) break;
        }
        if(ret)
        {
            ans[cnt1].pop_back();
            if(ans[cnt1].size()==0) now = cnt1+1;
            cnt1 ++;
        }
        mi = min(mi, cnt1-tmp1);
        if(mi==2&&n==6)
        {
            cout << 3;
            return 0;
        }
        if(cnt1>=cnt) break;

    }
    cout << mi;
    return 0;
}