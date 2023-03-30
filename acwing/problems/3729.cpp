#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
template<typename T>
class mystack1
{
private:
    T* data;
    unsigned int length;
    unsigned int max_len;
public:
    mystack1() {
        this->length = 0;
        this->max_len = 0;
        data = nullptr;
    }
    void push(T x) {
        if(length >= max_len) {
            T* tmp = data;
            max_len = max_len ? (max_len<<1):(1);
            data = new T[max_len];
            if(tmp) {
                // memcpy(data, tmp, sizeof(tmp));
                for (int i = 0; i < length; i++)
                    data[i] = tmp[i];
                delete[] tmp;
            }
        }
        data[length++] = x;
    }
    void pop() {
        if(length) --length;
    }
    bool empty() {
        return length == 0;
    }
    T& top() {
        return data[length - 1];
    }
    unsigned int size() {
        return length;
    }
    ~mystack1() {
        if(data) delete[] data;
    }
};
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    mystack1<int> ans;
    int mi = n;
    dec(i, n, 1)
    {
        int t = a[i];
        while(ans.size() < n && n - i + t > SZ(ans)) ans.push(1);
        if(ans.size() <= n - i) ans.push(0);
    }
    while(ans.size())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}