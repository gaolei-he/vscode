#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 2e3+10;
class Node
{
public:
    int x1, y1, x2, y2;
    double a;
    int k;
    int x, y, d, t;
    double I;
    int op;
    Node(int x1, int y1, int x2, int y2, double a)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->a = a;
        this->op = 1;
    }
    Node(int k)
    {
        this->k = k;
        this->op = 2;
    }
    Node(int x, int y, int d, double I, int t)
    {
        this->op = 3;
        this->d = d;
        this->x = x;
        this->y = y;
        this->I = I;
        this->t = t;
    }
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main()
{
    int m; cin >> m;
    vector<vector<double>> vec(N, vector<double>(N));
    vector<Node> querys;
    while(m --)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int x1, y1, x2, y2;
            double a;
            cin >> x1 >> y1 >> x2 >> y2 >> a;
            x1 += 1000, y1 += 1000, x2 += 1000, y2 += 1000;
            querys.push_back(Node(x1, y1, x2, y2, a));
        }
        else if(op == 2)
        {
            int k; cin >> k;
            querys.push_back(Node(k));
        }
        else if(op == 3)
        {
            int x, y, d, t;
            double I;
            cin >> x >> y >> d >> I >> t;
            x += 1000, y += 1000;
            querys.push_back(Node(x, y, d, I, t));
        }
    }
    auto go = [&](int &x, int &y, int &d, double &I)
    {
        int xx = dx[d], yy = dy[d];
        x += xx, y += yy;
        if(x > 2000 or y > 2000 or x < 0 or y < 0) return;
        if(fabs(vec[x][y]) > 0.1)
        {
            I = I * fabs(vec[x][y]);
            if(vec[x][y] > 0.1)
            {
                if(d == 0) d = 1;
                else if(d == 1) d = 0;
                else if(d == 2) d = d = 3;
                else if(d == 3) d = 2;
            }
            else if(vec[x][y] < -0.1)
            {
                if(d == 0) d = 3;
                else if(d == 1) d = 2;
                else if(d == 2) d = 1;
                else if(d == 3) d = 0;
            }
        }
    };
    for(auto &node : querys)
    {
        if(node.op == 1)
        {
            int x1, y1, x2, y2;
            double a = node.a;
            x1 = node.x1, x2 = node.x2;
            y1 = node.y1, y2 = node.y2;
            if(x1 > x2) swap(x1, x2), swap(y1, y2);
            if(x1 < x2 and y1 < y2) a = a;
            else a = -a;
            int op;
            if(a > 0) op = 1;
            else op = -1;
            for(x1 ++, y1 += op;x1 < x2; x1 ++, y1 += op)
            {
                vec[x1][y1] = a;
            }
        }
        else if(node.op == 2)
        {
            int k = node.k;
            int x1 = querys[k-1].x1, x2 = querys[k-1].x2;
            int y1 = querys[k-1].y1, y2 = querys[k-1].y2;
            double a = querys[k-1].a;
            if(x1 > x2) swap(x1, x2), swap(y1, y2);
            if(x1 < x2 and y1 < y2) a = a;
            else a = -a;
            int op;
            if(a > 0) op = 1;
            else op = -1;
            for(x1 ++, y1 += op;x1 < x2; x1 ++, y1 += op)
            {
                vec[x1][y1] = 0;
            }
        }
        else if(node.op == 3)
        {
            int x = node.x, y = node.y, t = node.t, d = node.d;
            double I = node.I;
            while(t --) go(x, y, d, I);
            if(floor(I) == 0) x = 1000, y = 1000;
            cout << x - 1000 << ' ' << y - 1000 << ' ' << floor(I) << endl;
        }
    }
    return 0;
}