#include <bits/stdc++.h>

using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int, vector<int>, less<int>> b;

    int q;
    cin >> q;
    while (q --)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            int x;
            scanf("%d", &x);
            if(a.size() == 0 && b.size() == 0) b.push(x);
            else if(a.size() == 0)
            {
                if(b.top() > x)
                {
                    a.push(b.top());
                    b.pop();
                    b.push(x);
                }
                else a.push(x);
            }
            else
            {
                if(a.size() == b.size())
                {
                    if(x > a.top())
                    {
                        b.push(a.top());
                        a.pop();
                        a.push(x);
                    }
                    else b.push(x);
                }
                else
                {
                    if(x > b.top()) a.push(x);
                    else
                    {
                        a.push(b.top());
                        b.pop();
                        b.push(x);
                    }
                }
            }
        }
        else cout << b.top() << endl;
    }
    
    return 0;
}