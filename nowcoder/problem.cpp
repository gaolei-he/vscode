/*
20 1
1
2
28
44
46
48
51
54
84
0
0
0
0
0
0
0
0
0
0
0
expected:
0
0
0
0
0
0
0
0
0
0
0
1
2
28
44
46
48
51
54
84
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    if(b.size() < 1) puts("WHAT?");
    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
    //if(b.size() < 1) return false;
    cout << &a << endl << &b << endl << endl;
    return true;
}
int main()
{
    int n, m;
    while (cin >> n)
    {
        cin >> m;
        vector<vector<int> >a;
        for (int i = 0; i < n; i++)
        {
            
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            
            a.push_back(tmp);
        }
        for(auto &i:a) cout << &i << endl;
        puts("");
        sort(a.begin(), a.end(), cmp);
        
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                cout << a[i][j];
                if(j == a[i].size() - 1) cout << endl;
                else cout << ' ';
            }
            
        }
    }
    
    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;
// class A {
// public:
//     int a, b;
// };

// bool cmp(A a, A b)
// {
//     puts("Good");
//     return false;
// }
// int main()
// {
//     A a[5];
//     for(int i=0;i<5;i++) a[i] = {1, 1};
//     sort(a, a+5, cmp);
//     return 0;
// }