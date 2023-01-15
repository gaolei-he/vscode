#include <iostream>
#include <cstring>

#include <queue>
#define scan scanf("%d", &a[i])
using namespace std;

const int N = 1e5+10;
int len1, len2, h1[N], h2[N];

void up1(int u)
{
    while(u/2&&h1[u/2]<h1[u])
    {
        swap(h1[u/2], h1[u]);
        u /= 2;
    }
}
void up2(int u)
{
    while (u/2&&h2[u/2]>h2[u])
    {
        swap(h2[u/2], h2[u]);
        u /= 2;
    }
    
}
void down2(int u)
{
    int t = u;
    if(u*2<=len2&&h2[u*2]<h2[t]) t = u * 2;
    if(u*2+1<=len2&&h2[u*2+1]<h2[t]) t = u * 2 + 1;
    if(t!=u)
    {
        swap(h2[t], h2[u]);
        down2(t);
    }
}
void down1(int u)
{
    int t = u;
    if(u*2<=len1&&h1[u*2]>h1[t]) t = u * 2;
    if(u*2+1<=len1&&h1[u*2+1]>h1[t]) t = u * 2 + 1;
    if(t!=u)
    {
        swap(h1[u], h1[t]);
        down1(t);
    }
}
int main()
{
        int m;
        cin >> m;
        int a[m+1];
        for(int i=1;i<=m;i++) scan;
        
        for(int i=1;i<=m;i++)
        {
            int x = a[i];
            if(len1==len2)
            {
                len1 ++;
                h1[len1] = x;
                up1(len1);
            }
            else
            {
                len2 ++;
                h2[len2] = x;
                up2(len2);
            }
            if(h1[1]>h2[1]&&len1&&len2)
            {
                swap(h1[1], h2[1]);
                down1(1), down2(1);
            }
            
            if(i&1) printf("%d\n", h1[1]);


        }

        
    
}

# if 0
int main()
{
        int m;
        cin >> m;
        int a[m+1];
        for(int i=1;i<=m;i++) scan;
        priority_queue<int, vector<int>, less<int>> a1;
        priority_queue<int, vector<int>, greater<int>> a2;
        
        for(int i=1;i<=m;i++)
        {
            if(a1.size()==a2.size()&&a2.size())
            {
                a1.push(a[i]);
                if(a1.top()>a2.top())
                {
                    int tmp1 = a1.top();
                    a1.pop();
                    int tmp2 = a2.top();
                    a2.pop();
                    a1.push(tmp2);
                    a2.push(tmp1);
                }
            }
            else if(a2.size()>=0&&a1.size())
            {
                a2.push(a[i]);
                if(a1.top()>a2.top())
                {
                    int tmp1 = a1.top();
                    a1.pop();
                    int tmp2 = a2.top();
                    a2.pop();
                    a1.push(tmp2);
                    a2.push(tmp1);
                }
            }
            else a1.push(a[i]);
            if(i&1)
            {
                

                printf("%d\n", (int) a1.top());
            }
        }

    
    
    return 0;
}
#endif