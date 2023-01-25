#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(l2 >= l1 && l2 <= r1) cout << l2 << endl;
        else if(r2 >=l1 && r2 <= r1) cout << max(l2, l1) << endl;
        else if(l1 >= l2 && l1 <= r2) cout << l1 << endl;
        else if(r1 >= l2 && r1 <= r2) cout << max(l1, l2) << endl;
        else cout << min(l1, r1) + min(l2, r2) << endl;

    }
    
    

    return 0;
}
