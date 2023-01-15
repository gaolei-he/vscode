#include <iostream>
using namespace std;
const int N = 1e5+10;
bool st[N];
int ans = 0;
string tmp, str[N];
int n;
int cal()
{
    int cnt1 = 0;
    tmp = tmp.substr(1, 100);
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == ' ')
        {
            cnt1 ++;
            int j;
            for (j=1;tmp[i-j] != ' ';j++)
            {
                int k;
                for(k=1;k<=j;k++)
                {
                    if(tmp[i + k] != tmp[i - j + k - 1]) break;
                }
                if(k>j) break;
            }
            cnt1 += j;
            
        }
    }
    tmp = ' ' + tmp;
    int tmp3 = tmp.size() -1 -cnt1;
    //if(tmp3==30) cout << tmp << endl;
    return tmp.size() - 1 - cnt1;
}

bool check(string s)
{
    int i = tmp.size() - 1;
    while (tmp[i] != ' ') i --;
    int tmp2 = i;
    for(i++;i<tmp.size();i++)
    {
        if(tmp[i] == s[0])
        {
            int j;
            for (j = 0; i + j < tmp.size(); j++)
            {
                if(s[j] != tmp[i+j]) break;
            }
            
            if(i + j == tmp.size() && j == s.size() && tmp2 + 1 == i) return true;
            else if(i+j == tmp.size() && (j == s.size() || tmp2 + 1 == i) ) return false;
            else if(j+i == tmp.size()) return true;
        }
    }
    return false;
}

void dfs(int x)
{
    st[x] = true;
    for (int i=1;i<=n*2;i++)
    {
        if(st[i] == false && check(str[i]))
        {
            tmp += ' ' + str[i];
            dfs(i);
        }
    }
    ans = max(cal(), ans);
    while (tmp.back() != ' ') tmp.pop_back();
    tmp.pop_back();
    st[x] = false;
    return;
}

int main()
{
    
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> str[i];
        str[i + n] = str[i];
    }

    char op;
    cin >> op;
    for (int i = 1; i <= n; i++)
    {
        if (str[i][0] == op)
        {
            tmp = ' ' + str[i];
            dfs(i);
        }
    }
    cout << ans;
    return 0;
}