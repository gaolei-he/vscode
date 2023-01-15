#include <iostream>
#include <cstring>

using namespace std;
const int N = 5000;
char ans[N+10][N+10];

void mystrcpy(char *s1,const char *s2)
{
    int i = 0, j = 0;
    while(s1[++i]);
    int length = strlen(s2);
    while(j<length)
    {
        s1[i++] = s2[j++];
    }
    return;
}

int main()
{
    int n;
    //memset(ans, ' ', sizeof(ans));
    cin >> n;
    strcpy(ans[N-1], " /\\ ");
    strcpy(ans[N], "/__\\");
    int tmp = N;
    while(--n)
    {
        int length = strlen(ans[N])*2;
        string tmps = "";
        while(tmps.size()<length/4)
            tmps += ' ';
        for(int i=N-length/4;i>N-length/2;i--)
        {
            strcpy(ans[i], tmps.c_str());
            
        }
        for(int i=N;i>N-length/4;i--)
        {
            mystrcpy(ans[i-length/4], ans[i]);
            mystrcpy(ans[i], ans[i]);
            mystrcpy(ans[i-length/4], tmps.c_str());
        }

    }
    for(int i=1;i<=N;i++) if(ans[i][0]) printf("%s\n", ans[i]);
    return 0;
}