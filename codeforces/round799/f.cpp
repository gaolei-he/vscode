#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int st[10];
int q[] = {3,12,21,30,49,58,67,76,85,94,102,111,120,139,148,157,166,175,184,193,201,210,229,238,247,256,265,274,283,292,300,319,328,337,346,355,364,373,382,391,409,418,427,436,445,454,463,472,481,490,508,517,526,535,544,553,
562,571,580,599,607,616,625,634,643,652,661,670,689,698,706,715,724,733,742,751,760,779,788,797,805,814,823,832,841,850,869,878,887,896,904,913,922,931,940,959,968,977,986,995};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(st, 0, sizeof(st));
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            st[x%10] ++;
            
        }
        bool res = false;
        for(int i=0;i<100;i++)
        {
            int l1 = q[i] / 100, l2 = q[i] % 100 / 10, l3 = q[i] % 10;
            int tmp[3];
            tmp[0] = l1, tmp[1] = l2, tmp[2] = l3;
            sort(tmp, tmp+3);
            if(tmp[0] == tmp[1] && tmp[2] == tmp[1])
            {
                if(st[tmp[0]] < 3) continue;
                res = true;
                //cout << q[i];
                break;
            }
            else if(tmp[0] == tmp[1] || tmp[1] == tmp[2])
            {
                if(st[tmp[1]] < 2) continue;
                if(tmp[0] == tmp[1] && st[tmp[2]]) res = true;
                else if(tmp[1] == tmp[2] && st[tmp[0]]) res = true;
                //if(res) cout << q[i];
                if(res) break;
            }
            else if(l1 != l2 && l1 != l3 && l2 != l3 && st[l1] && st[l2] && st[l3])
            {
                res = true;
                //cout << q[i];
                break;
            }

        }
        if(res) puts("YES");
        else puts("NO");
    }
    
    return 0;
}