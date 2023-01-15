#include <iostream>
#include <cstring>
using namespace std;

int f(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else return f(n-1)+f(n-2);
}
string add(string s1, string s2)
{
    string res = "";
    int length1 = s1.length() - 1, length2 = s2.length() - 1;
    while (length1 != -1 && length2 != -1)
        res = (char)(s1[length1--] + s2[length2--] - 48) + res;
    length1++, length2++;
    while (length1--)
        res = s1[length1] + res;
    while (length2--)
        res = s2[length2] + res;
    int length3 = res.length() - 1;
    while (length3)
    {
        if (res[length3] > '9')
        {
            res[length3 - 1] += (res[length3] - 48) / 10;
            res[length3] = (res[length3] - 48) % 10 + 48;
        }
        length3--;
    }
    if (res[0] > '9')
    {
        res = (char)((res[length3] - 48) / 10 + 48) + res;
        res[1] = (res[1] - 48) % 10 + 48;
    }
    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    string a[1009];
    a[1] = "1", a[2] = "2";
    for(int i=3;i<=n-m;i++) a[i] = add(a[i-1], a[i-2]);
    cout << a[n-m];
    return 0;
}