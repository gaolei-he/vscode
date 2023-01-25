#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
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
    T * a = new T[4];
    T & operator[](int k)
    {return *(a+k);}
    int cnt = 0;
    int & size() {return cnt;}
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

    T back() { return *(a+cnt-1); }

    void clear() { cnt = 0;}
    T *begin(){return a;}
    T *end(){return a+cnt;}
    void erase(T *tmp1, T *tmp2)
    {
        myvector<T> tmp;
        int j = 0;
        for (int i = 0; i < tmp1-a; i++, j++) tmp[j] = *(a+i);
        for (int i = 0; tmp2+i!=this->end(); i++, j++) tmp[j] = *(tmp2 + i);

        cnt -= tmp2 - tmp1;
        
        delete [] a;
        a = tmp.a;
    }


    void operator=(myvector<T> tmp)
    {
        this->size() = tmp.size();
        for (int i = 0; i < tmp.size(); i++)
        {
            *(a+i) = tmp[i];
        }
        
    }
    //~myvector(){if(a)delete []a;}
};


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0, l, r, ans1;
        int n;
        scanf("%d", &n);
        map<int, myvector<int>> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if(q.find(x) == q.end())
            {
                q[x].push_back(1);
                q[x].push_back(i);
                q[x].push_back(i);
            }
            else
            {
                int old = q[x][0], l1 = q[x][1], l2 = q[x][2];
                q[x].clear();
                if(old - (i - l2) + 2 > 0)
                {
                    
                    q[x].push_back(old - (i - l2) + 2);
                    q[x].push_back(l1);
                    q[x].push_back(i);
                }
                else
                {
                    q[x].push_back(1);
                    q[x].push_back(i);
                    q[x].push_back(i);
                }
            }
            if(ans < q[x][0])
            {
                ans = q[x][0];
                l = q[x][1] + 1;
                r = q[x][2] + 1;
                ans1 = x;
            }
        }
        cout << ans1 << ' ' << l << ' ' << r << endl;

    }
    
    return 0;
}

