#include <set>
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    set<string> st;
    while(n --)
    {
        string tmp; cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size() << endl;
    return 0;
}