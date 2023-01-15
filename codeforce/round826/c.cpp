#include <iostream>
using namespace std;
int a[2010];
int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        int ans = n, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp_ans = 0;
            sum += a[i];
            for (int j = 0; j < n; j++)
            {
                int tmp = 0;
                int pos = j;
                while(tmp < sum && j < n) tmp += a[j++];
                if(tmp != sum) {tmp_ans = 0; break;}
                // j --;
                tmp_ans = max(tmp_ans, j - pos);
                j --;
            }
            if(tmp_ans) ans = min(ans, tmp_ans);
        }
        cout << ans << endl;
        
    }
    
    return 0;
}
