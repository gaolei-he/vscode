#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 4e5+10;
int ne[N];
char str[N];
int main()
{
    while (scanf("%s", str+1) != EOF)
    {
        int length1 = strlen(str+1);
        for(int i=2, j=0;i<=length1;i++)
        {
            while(j && str[i] != str[j+1]) j = ne[j];
            if(str[j+1] == str[i]) j ++;
            ne[i] = j;
        }
        vector<int> a;
        for(int i=ne[length1];i;i=ne[i])
            a.push_back(i);
        a.push_back(length1);
        sort(a.begin(), a.end());
        for(int i=0;i<a.size();i++) cout << a[i] << ' ';
        puts("");
    }
    
    return 0;
}