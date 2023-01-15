#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
class myvector
{
private:
    bool check(int tmp)
    {
        if(tmp < 32) return false;
        while(!(tmp&1)) tmp >>= 1;
        tmp >>= 1;
        if(tmp) return false;
        else return true; 
    }
public:
    T * a = new T[32];
    T operator[](int k)
    {return *(a+k);}
    int cnt = 0;
    int size() {return cnt;}
    void push_back(T k)
    {
        if(this->check(cnt))
        {
            T *tmp = new T[(cnt)*2];
            memcpy(tmp, a, sizeof(T)*cnt);
            delete []a;
            a = tmp;
        }
        *(a + cnt ++) = k;
    }
    void pop_back() { cnt--; }
    int back() { return *(a+cnt-1); }
    void clear() { cnt = 0;}
    T *begin(){return a;}
    T *end(){return a+cnt;}
    void erase(T *tmp1, T *tmp2)
    {
        cnt = tmp1 - a;
    }
};

myvector<int> div(myvector<int> &A, int b, long long &r)
{
    myvector<int> C;
    r = 0;
    for(int i=A.size()-1;i>=0;i--)
    {
        r = r * 10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    myvector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    long long r;
    auto C = div(A, b, r);

    for(int i=C.size()-1;i>=0;i--) printf("%d", C[i]);
    //cout << endl << r << endl;
    return 0;
}