#include <iostream>
#include <vector>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int n, m;
const int N = 1e3+10;
int f[N];
class A:public vector<int>
{
public:
    bool operator<(A a) {
        for(int i=0;i<a.size() && i<this->size();i++) {
            if((*this)[i] < a[i]) return true;
            else if((*this)[i] > a[i]) return false;
        }
        if(a.size() != this->size()) return this->size() < a.size();
        return true;
    }
};
int main()
{
    cin >> n >> m;
    vector<A> vec;
    vec.resize(m+1);
    rep(i, 1, n)
    {
        int v, w;
        cin >> v >> w;
        dec(j, m, v)
        {
            if(f[j] < f[j-v] + w)
            {
                f[j] = f[j-v] + w;
                vec[j] = vec[j-v];
                vec[j].push_back(i);
            }
            else if(f[j] == f[j-v]+w)
            {
                auto tmp = vec[j-v];
                tmp.push_back(i);
                if(tmp < vec[j]) vec[j] = tmp;
            }
        }

    }
    for(auto i:vec[m]) cout << i << ' ';
    return 0;
}