#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
const int N = 400;
bool sta[N][N];
char str[N][N];
typedef pair<int, int> pii;
pair<pii, pii> a[26];
bool cmp(pii a, pii b)
{
    if (a.first == b.first && a.second == b.second)
        return true;
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);

    pii st, ed;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char op = str[i][j];
            if (op == '@')
                st.first = i, st.second = j;
            else if (op == '=')
                ed.first = i, ed.second = j;
            else if (op == '#' || op == '.')
                continue;

            if (a[op - 'A'].first.first)
                a[op - 'A'].second.first = i, a[op - 'A'].second.second = j;
            else
                a[op - 'A'].first.first = i, a[op - 'A'].first.second = j;
        }
    }
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    deque<pii> q, tmp;
    q.push_back(st);
    sta[st.first][st.second] = true;
    bool flag = false;
    int ans = 0;

    while (q.size())
    {
        tmp = q;
        q = deque<pii>();
        ans++;
        while (tmp.size())
        {
            auto point = tmp.front();
            tmp.pop_front();
            // cout << point.first << ' ' << point.second << endl;
            for (int i = 0; i < 4; i++)
            {
                int tx = point.first + dx[i], ty = point.second + dy[i];
                char op = str[tx][ty];
                if (sta[tx][ty])
                    continue;
                if (op == '.')
                {
                    sta[tx][ty] = true;
                    q.push_back({tx, ty});
                }
                else if (op >= 'A' && op <= 'Z')
                {
                    sta[tx][ty] = true;
                    if (cmp(a[op - 'A'].first, {tx, ty}))
                    {
                        auto it = a[op - 'A'].second;
                        q.push_back(it);
                        // sta[it.first][it.second] = true;
                    }
                    else
                    {
                        auto it = a[op - 'A'].first;
                        q.push_back(it);
                        // sta[it.first][it.second] = true;
                    }
                }
                // q.back();
                else if (str[tx][ty] == '=')
                {
                    // cout << "###" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    cout << ans << endl;
    return 0;
}