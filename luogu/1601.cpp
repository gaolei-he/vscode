#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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


myvector<int> add(myvector<int> &A, myvector<int> &B)
{
    myvector<int> C;
    int t = 0;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size()) t += A[i];
        if(i<B.size()) t += B[i];
        C.push_back(t%10);
        t /= 10;
    }
    if(t) C.push_back(t);
    while(C.size()>1&&C.back()==0) C.pop_back();
    reverse(C.begin(), C.end());
    return C;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    myvector<int> A, B;
    for(int i=s1.size()-1;i>=0;i--) A.push_back(s1[i]-'0');
    for(int i=s2.size()-1;i>=0;i--) B.push_back(s2[i]-'0');

    auto C = add(A, B);

    for(int i=0;i<C.size();i++) printf("%d", C[i]);
    return 0;
}