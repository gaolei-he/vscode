#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    set<int> st;
    while(k --)
    {
        int x, y; cin >> x >> y;
        if(y and !st.count(y)) ans ++;
        st.insert(x);
    }
    cout << ans << endl;
    return 0;
}