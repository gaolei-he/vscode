#include <iostream>
#include <vector>
using namespace std;
void f(int x)
{
    for (int i = 0; i < 32; i++)
    {
        cout << ((x >> (31 - i)) & 1);
    }
    cout << " ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(39, vector<int>(n));
    for(int i=0;i<n;i++) cin >> vec[0][i];
    for(int i=1;i<39;i++)
    {
        for(int j=0;j<n;j++)
        {
            vec[i][j] = vec[i-1][j] ^ vec[i][j-1];
            f(vec[i][j]);
        }
        cout << endl;
    }
    m %= 16;
    // for(int i=0;i<n;i++)
    // {
    //     cout << vec[m][i] << " ";
    // }
    return 0;
}