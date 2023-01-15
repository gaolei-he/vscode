#include <iostream>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <queue>
#define rep(i, a, n) for (int i = (a); i <= (n); ++i)
#define dec(i, n, a) for (int i = (n); i >= (a); --i)
using namespace std;
string a, b;
string tmp1 = " f", tmp2 = "fe";
int maxx = 0;
bool debug = true;
pair<string, string> out;
string convert(string t, int op)
{
    char a, b, c;
    if(op <= 2) a = t[3-1], b = t[6-1], c = t[9-1];
    else if(op <= 4) a = t[1-1], b = t[2-1], c = t[3-1];
    else if(op <= 6) a = t[1-1], b = t[4-1], c = t[7-1];
    else if(op <= 8)a = t[7-1], b = t[8-1], c = t[9-1];
    else if(op <= 10) a = t[25-1], b = t[26-1], c = t[27-1];
    else a = t[19-1], b = t[20-1], c = t[21-1];

    // tmp1 = t;
    switch (op)
    {
    case 1:
        t[9-1] = t[27-1], t[6-1] = t[24-1], t[3-1] = t[21-1];
        t[27-1] = t[46-1], t[24-1] = t[49-1], t[21-1] = t[52-1];
        t[46-1] = t[45-1], t[49-1] = t[42-1], t[52-1] = t[39-1];
        t[39-1] = a, t[42-1] = b, t[45-1] = c;
        a = t[10-1], b = t[11-1], c = t[12-1];
        t[10-1] = t[12-1], t[11-1] = t[15-1], t[12-1] = t[18-1];
        t[15-1] = t[17-1], t[18-1] = t[16-1];
        t[17-1] = t[13-1], t[16-1] = a, t[13-1] = b;
        break;
    case 2:
        t[3-1] = t[39-1], t[6-1] = t[42-1], t[9-1] = t[45-1];
        t[39-1] = t[52-1], t[42-1] = t[49-1], t[45-1] = t[46-1];
        t[52-1] = t[21-1], t[49-1] = t[24-1], t[46-1] = t[27-1];
        t[21-1] = a, t[24-1] = b, t[27-1] = c;
        a = t[10-1], b = t[11-1], c = t[12-1];
        t[12-1] = t[10-1], t[11-1] = t[13-1], t[10-1] = t[16-1];
        t[13-1] = t[17-1], t[16-1] = t[18-1], t[17-1] = t[15-1];
        t[18-1] = c, t[15-1] = b;
        break;
    case 3:
        t[1-1] = t[28-1], t[2-1] = t[29-1], t[3-1] = t[30-1];
        t[30-1] = t[48-1], t[29-1] = t[47-1], t[28-1] = t[46-1];
        t[48-1] = t[12-1], t[47-1] = t[11-1], t[46-1] = t[10-1];
        t[10-1] = a, t[11-1] = b, t[12-1] = c;
        a = t[19-1], b = t[20-1], c = t[21-1];
        t[19-1] = t[21-1], t[20-1] = t[24-1], t[21-1] = t[27-1];
        t[24-1] = t[26-1], t[27-1] = t[25-1], t[26-1] = t[22-1];
        t[25-1] = a, t[22-1] = b;
        break;
    case 4:
        t[1-1] = t[10-1], t[2-1] = t[11-1], t[3-1] = t[12-1];
        t[10-1] = t[46-1], t[11-1] = t[47-1], t[12-1] = t[48-1];
        t[48-1] = t[30-1], t[47-1] = t[29-1], t[46-1] = t[28-1];
        t[28-1] = a, t[29-1] = b, t[30-1] = c;
        a = t[19-1], b = t[20-1], c = t[21-1];
        t[19-1] = t[25-1], t[20-1] = t[22-1], t[21-1] = a;
        t[22-1] = t[26-1], t[25-1] = t[27-1], t[26-1] = t[24-1];
        t[27-1] = c, t[24-1] = b;
        break;
    case 5:
        t[1-1] = t[37-1], t[4-1] = t[40-1], t[7-1] = t[43-1];
        t[37-1] = t[54-1], t[40-1] = t[51-1], t[43-1] = t[48-1];
        t[48-1] = t[25-1], t[51-1] = t[22-1], t[54-1] = t[19-1];
        t[19-1] = a, t[22-1] = b, t[25-1] = c;
        a = t[28-1], b = t[29-1], c = t[30-1];
        t[28-1] = t[30-1], t[29-1] = t[33-1], t[30-1] = t[36-1];
        t[33-1] = t[35-1], t[36-1] = t[34-1], t[35-1] = t[31-1];
        t[34-1] = a, t[31-1] = b;
        break;
    case 6:
        t[1-1] = t[19-1], t[4-1] = t[22-1], t[7-1] = t[25-1];
        t[19-1] = t[54-1], t[22-1] = t[51-1], t[25-1] = t[48-1];
        t[48-1] = t[43-1], t[51-1] = t[40-1], t[54-1] = t[37-1];
        t[37-1] = a, t[40-1] = b, t[43-1] = c;
        a = t[28-1], b = t[29-1], c = t[30-1];
        t[28-1] = t[34-1], t[29-1] = t[31-1], t[30-1] = a;
        t[31-1] = t[35-1], t[34-1] = t[36-1], t[35-1] = t[33-1];
        t[36-1] = c, t[33-1] = b;
        break;
    case 7:
        t[7-1] = t[16-1], t[8-1] = t[17-1], t[9-1] = t[18-1];
        t[16-1] = t[52-1], t[17-1] = t[53-1], t[18-1] = t[54-1];
        t[52-1] = t[34-1], t[53-1] = t[35-1], t[54-1] = t[36-1];
        t[34-1] = a, t[35-1] = b, t[36-1] = c;
        a = t[37-1], b = t[38-1], c = t[39-1];
        t[37-1] = t[39-1], t[38-1] = t[42-1], t[39-1] = t[45-1];
        t[42-1] = t[44-1], t[45-1] = t[43-1], t[44-1] = t[40-1];
        t[43-1] = a, t[40-1] = b;
        break;
    case 8:
        t[7-1] = t[34-1], t[8-1] = t[35-1], t[9-1] = t[36-1];
        t[34-1] = t[52-1], t[35-1] = t[53-1], t[36-1] = t[54-1];
        t[52-1] = t[16-1], t[53-1] = t[17-1], t[54-1] = t[18-1];
        t[16-1] = a, t[17-1] = b, t[18-1] = c;
        a = t[37-1], b = t[38-1], c = t[39-1];
        t[37-1] = t[43-1], t[38-1] = t[40-1], t[39-1] = a;
        t[40-1] = t[44-1], t[43-1] = t[45-1], t[44-1] = t[42-1];
        t[45-1] = c, t[42-1] = b;
        break;
    case 9:
        t[25-1] = t[10-1], t[26-1] = t[13-1], t[27-1] = t[16-1];
        t[10-1] = t[39-1], t[13-1] = t[38-1], t[16-1] = t[37-1];
        t[37-1] = t[30-1], t[38-1] = t[33-1], t[39-1] = t[36-1];
        t[30-1] = c, t[33-1] = b, t[36-1] = a;
        a = t[1-1], b = t[2-1], c = t[3-1];
        t[1-1] = t[3-1], t[2-1] = t[6-1], t[3-1] = t[9-1];
        t[6-1] = t[8-1], t[9-1] = t[7-1], t[8-1] = t[4-1];
        t[7-1] = a, t[4-1] = b;
        break;
    case 10:
        t[25-1] = t[36-1], t[26-1] = t[33-1], t[27-1] = t[30-1];
        t[30-1] = t[37-1], t[33-1] = t[38-1], t[36-1] = t[39-1];
        t[37-1] = t[16-1], t[38-1] = t[13-1], t[39-1] = t[10-1];
        t[10-1] = a, t[13-1] = b, t[16-1] = c;
        a = t[1-1], b = t[2-1], c = t[3-1];
        t[1-1] = t[7-1], t[2-1] = t[4-1], t[3-1] = a;
        t[4-1] = t[8-1], t[7-1] = t[9-1], t[8-1] = t[6-1];
        t[9-1] = c, t[6-1] = b;
        break;
    case 11:
        t[19-1] = t[12-1], t[20-1] = t[15-1], t[21-1] = t[18-1];
        t[12-1] = t[45-1], t[15-1] = t[44-1], t[18-1] = t[43-1];
        t[43-1] = t[28-1], t[44-1] = t[31-1], t[45-1] = t[34-1];
        t[34-1] = a, t[31-1] = b, t[28-1] = c;
        a = t[46-1], b = t[47-1], c = t[48-1];
        t[46-1] = t[52-1], t[47-1] = t[49-1], t[48-1] = a;
        t[49-1] = t[53-1], t[52-1] = t[54-1], t[53-1] = t[51-1];
        t[54-1] = c, t[51-1] = b;
        break;
    case 12:
        t[19-1] = t[34-1], t[20-1] = t[31-1], t[21-1] = t[28-1];
        t[28-1] = t[43-1], t[31-1] = t[44-1], t[34-1] = t[45-1];
        t[43-1] = t[18-1], t[44-1] = t[15-1], t[45-1] = t[12-1];
        t[12-1] = a, t[18-1] = b, t[15-1] = c;
        a = t[46-1], b = t[47-1], c = t[48-1];
        t[46-1] = t[48-1], t[47-1] = t[51-1], t[48-1] = t[54-1];
        t[51-1] = t[53-1], t[54-1] = t[52-1], t[53-1] = t[49-1];
        t[52-1] = a, t[49-1] = b;
        break;
    default:
        break;
    }
    // tmp2 = t;
    // sort(tmp2.begin(), tmp2.end());
    // sort(tmp1.begin(), tmp1.end());
    // if(tmp1 != tmp2 && debug) cerr << op << endl;
    return t;
}
int expand(unordered_map<string, string>& ma, unordered_map<string, string>& mb, queue<string>& a, string t)
{
    rep(i, 1, 12)
    {
        string ans = convert(t, i);
        if(ma.count(ans)) continue;
        else if(mb.count(ans))
        {
            out.first = ma[t] + (char)i;
            out.second = mb[ans];
            return 1;
        }
        if(ma[t].size() > 10) continue;
        a.push(ans);
        ma[ans] = ma[t] + (char)i;
        // if(ma[ans].size() > maxx)
        // {
        //     maxx = ma[ans].size();
        //     cerr << maxx << endl;
        // }
        // if(ma[ans].size() == 2 && ma[ans][1] == 8 && ma[ans][0] == '0') tmp1 = ans;
        // else if(ma[ans].size() == 4 && ma[ans][1] == ma[ans][2] && ma[ans][3] == ma[ans][2] && ma[ans][2] == 7 && ma[ans][0] == '0') tmp2 = ans;
        // sort(ans.begin(), ans.end());
        // if(ans != b && debug)
        // {
    
        //     cerr << ans << endl;
        //     cerr << b << endl;
        //     cerr << ans.size() << endl;
        //     cerr << i << endl;
        //     debug = false;
        // }
    }
    return -1;

}

void bfs()
{
    unordered_map<string, string> ma, mb;
    queue<string> qa, qb;
    qa.push(a); ma.insert({a, "0"});
    qb.push(b); mb.insert({b, "9"});

    while(qa.size() && qb.size())
    {
        string t;
        int step = -1;
        if(qa.size() > qb.size()) t = qb.front(), qb.pop(), step = expand(mb, ma, qb, t);
        else t = qa.front(), qa.pop(), step = expand(ma, mb, qa, t);
        if(step != -1) break;
    }
}
void print()
{
    int cnt = 0;
    function<void(int, bool)> f = [&](int i, bool flag) {
        if(!flag) if(i&1) i++; else i--;
        cout << (++ cnt) << ' ';
        switch (i)
        {
        case 1: cout << "右 ↓"; break;
        case 2: cout << "右 ↑"; break;
        case 3: cout << "上 →"; break;
        case 4: cout << "上 ←"; break;
        case 5: cout << "左 ↑"; break;
        case 6: cout << "左 ↓"; break;
        case 7: cout << "下 ←"; break;
        case 8: cout << "下 →"; break;
        case 9: cout << "前 ←"; break;
        case 10: cout << "前 →"; break;
        case 11: cout << "后 ←"; break;
        case 12: cout << "后 →"; break;
        default:
            break;
        }
        cout << endl;
    };
    if(out.first.front() != '0') swap(out.first, out.second);
    for(auto i:out.first) if(i >= 1 && i <= 8) f(i, true);
    reverse(out.second.begin(), out.second.end());
    for(auto i:out.second) if(i >= 1 && i <= 8) f(i, false);
    // cerr<< tmp1 << endl << tmp2 << endl;


}
int main()
{
    rep(i, 0, 53)
    {
        char op; cin >> op;
        a.push_back(op);
    }
    rep(i, 1, 6)
        rep(j, 1, 9)
            b.push_back(i+'0');
    tmp1 = a;
    sort(tmp1.begin(), tmp1.end());

    if(a == b) return 0;
    if(tmp1 != b) cerr << "Input error\n" << tmp1 << endl << b << endl << "Input cmp\n";
    bfs();
    print();
    // tmp1 = b;
    // tmp1 = convert(tmp1, 8);
    // tmp2 = convert(convert(convert(b, 7), 7), 7);
    // if(tmp1 == tmp2) cout << "7" << endl;
    return 0;
}