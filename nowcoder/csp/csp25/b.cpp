#include <iostream>
#include <vector>

using namespace std;

const int N = 4e5 + 10;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vec(N);
    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;
        vec[max(0, t-c+1)] += 1;
        vec[t+1] -= 1;
    }
    for(int i=1;i<=N-10;i++) vec[i] += vec[i-1];
    while(m --)
    {
        int q; cin >> q;
        q += k;
        cout << vec[q] << endl;
    }
    
    return 0;
}