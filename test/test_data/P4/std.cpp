#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    map<int, vector<string>> mp;
    set<string> st;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin >> s >> x;
        st.insert(s);
        mp[x].push_back(s);
    }
    // cout << st.size() << ' ' << n << endl;
    if(st.size() != n) exit(-1);
    if(mp.rbegin()->second.size() > 1) cout << "wake up, Third!" << endl;
    else cout << mp.rbegin()->second.front() << endl;
    return 0;
}