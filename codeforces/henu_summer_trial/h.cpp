#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <ctime>
using namespace std;
int prime[] = {2,3,5,7,11,13,17,19};
int main()
{
    int a, b, c, t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d %d", &a, &b, &c);
        int mi = min(a, min(b, c));
        bool res = false;
        int t = clock();
        for (int i = 0; i < 10000; i++)
        {
            if(clock()-t>100)
            {
                res = true;
                break;
            }
            int tmpa = a, tmpb = b, tmpc = c;
            if(prime[i]>mi)
            {
                res = true;
                break;
            }
            tmpa -= prime[i], tmpb -= prime[i], tmpc -= prime[i];
            vector<int> a1;
            for (int i = 0; i < 10000; i++)
            {
                if(prime[i] > tmpa) break;
                else if(tmpa % prime[i] == 0)
                {
                    a1.push_back(prime[i]);
                    tmpa /= prime[i];
                    i = 0;
                }
            }
            vector<int> b1;
            for (int i = 0; i < 10000; i++)
            {
                if(prime[i] > tmpb) break;
                else if(tmpb % prime[i] == 0)
                {
                    b1.push_back(prime[i]);
                    tmpb /= prime[i];
                    i = 0;
                }
            }
            vector<int> c1;
            for (int i = 0; i < 10000; i++)
            {
                if(prime[i] > tmpc) break;
                else if(tmpc % prime[i] == 0)
                {
                    c1.push_back(prime[i]);
                    tmpc /= prime[i];
                    i = 0;
                }
            }
            vector<int> tmp1, tmp2;
            set_intersection(a1.begin(), a1.end(), b1.begin(), b1.end(), inserter(tmp1, tmp1.begin()));
            set_intersection(tmp1.begin(), tmp1.end(), c1.begin(), c1.end(), inserter(tmp2, tmp2.begin()));
            if(tmp2.size())
            {
                cout << tmp2[0] << endl;
                res = false;
                break;
            }
            
        }
        if(res) cout << -1 << endl;
        
    }
    
    
    
    return 0;
}
/*
2 2 3 29 
2 7 29
17 29
*/