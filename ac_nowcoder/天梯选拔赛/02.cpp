#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    multiset<int> a;
    int num;
    for(int i=0;i<n;i++)
    {
        double out;
        cin >> num;
        a.insert(num);
        multiset<int>::iterator j;
        j = a.begin();
        //if(i&1) j++;
        for(int k=0;k<i/2;k++) j++;
        if(i&1) out = (*(j++) + *j)*1.0/2;
        else out = * j;
        cout << out << endl;
    }/*
    multiset<int>::iterator i;
    for(i=a.begin();i!=a.end();i++)
        printf("%d ", *i);*/
    return 0;
}
//multiset