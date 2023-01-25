#include <iostream>
using namespace std;
int main()
{
    int t;
    
    cin >> t;
    while (t--)
    {
        string s;   
        cin >> s;
        int n0 = 0, n1 = 0;
        int ne1[s.size()+1] = {0}, ne2[s.size()+1] = { 0 };
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '0')
            {
                n0 ++;
                ne2[i] = i;
            }

            ne2[i+1] = ne2[i];
        }
        
        for(int i=s.size();i>=0;i--)
        {
            if(s[i] == '0') ne1[i] = i;
            ne1[i-1] = ne1[i];
        }
        

        int tmp = 0;
        int i = 0, j = s.size() - 1;
        while(n0!=n1 && i<=j)
        {
            if(n1>=n0)
            {
                break;

            }
            while (s[i] == '0') i++, n0--;
            while (s[j] == '0') j--, n0--;
            int cnti = 0, cntj = 0, cnti0 = 0, cntj0 = 0;
            int tmpi = i, tmpj = j;
            while (s[tmpi] == '1') tmpi ++;
            cnti = tmpi - i;
            while (s[tmpj] == '1') tmpj --;
            cntj = j - tmpj;

            while(s[tmpi] == '0') tmpi ++;
            cnti0 = tmpi - cnti;
            while(s[tmpj] == '0') tmpj --;
            cntj0 = cntj - tmpj;
            
            if(cnti0 * 1.0 / cnti > cntj0 * 1.0 / cntj)
            {
                n0 -= cnti0;
                n1 += cnti;
            }
            else
            {
                n0 -= cntj0;
                n1 += cntj;
            }

            

        }
    cout << max(n0, n1) << endl;
        
    }
    

    return 0;
}