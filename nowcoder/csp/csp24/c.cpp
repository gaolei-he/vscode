#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int w, s;
string code;
vector<int> first;

void calc()
{
    queue<int> q;
    int status = 0;
    auto convert = [&](char c)
    {
        if(status == 0 and c >= 'a' and c <= 'z') q.push(27);
        else if(status == 0 and c >= '0' and c <= '9') q.push(28);
        else if(status == 1 and c >= '0' and c <= '9') q.push(28);
        else if(status == 2 and c >= 'a' and c <= 'z') q.push(27);
        else if(status == 2 and c >= 'A' and c <= 'Z') q.push(28);
        else if(status == 1 and c >= 'A' and c <= 'Z')q.push(28), q.push(28);
        if(c >= 'A' and c <= 'Z') status = 0;
        else if(c >= 'a' and c <= 'z') status = 1;
        else status = 2;
    };
    auto get_val = [&](char c)
    {
        int res = 0;
        if(c >= 'a' and c <= 'z') res = c - 'a';
        else if(c >= 'A' and c <= 'Z') res = c - 'A';
        else res = c - '0';
        return res;
    };
    for(auto c : code)
    {
        convert(c);
        q.push(get_val(c));
    }
    if(q.size() % 2 != 0) q.push(29);
    queue<int> q1;
    while(q.size())
    {
        int h = q.front();
        q.pop();
        int l = q.front();
        q.pop();
        q1.push(30 * h + l);
    }
    int val = 1 + q1.size();
    if(s >= 0) val += 1 << (s + 1);
    int cnt = (w - val % w) % w;
    while(cnt --) q1.push(900);
    first.push_back(q1.size() + 1);
    while(q1.size()) first.push_back(q1.front()), q1.pop();
}

void check()
{
    if(s < 0) return;

    int k = 1 << (s + 1);
}

int main()
{
    cin >> w >> s;
    cin >> code;

    calc();

    check();
    for(auto x : first) cout << x << endl;
    return 0;
}