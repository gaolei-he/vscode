#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
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
int a, b, p1;
const int N = 1e3+10;
int p[N];

bool isPrime(int x)
{
    if(x<=1||x==4) return false;
    
    else if(x==2||x==3) return true;
    else if(x%2==0||x%3==0) return false;
    else
    {
        for(int i=5;i*i<=x;i+=6) if(x%i==0||(x+2)%i==0) return false;
    }
    return true;
}

int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
bool f(int x, int y)
{
    int r = min(x, y);
    for(int i=p1;i<=r;i++)
    {
        if(x%i==0&&y%i==0&&isPrime(i)) return true;
    }
    return false;
}


int main()
{
    cin >> a >> b >> p1;
    for(int i=a;i<=b;i++) p[i] = i;

    for(int i=a;i<b;i++)
    {
        //if(find(i)!=i) continue;
        for(int j=a;j<=b;j++)
        {
            if(f(i, j)&&find(i)!=find(j)) p[find(i)] = find(j);
        }
    }
    myvector<int> ans;
    for(int i=a;i<=b;i++)
    {
        ans.push_back(find(i));
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size();
    
}