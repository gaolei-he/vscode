#include <bits/stdc++.h>

using namespace std;

#define L 27             //地点数
#define D 30             // 天数
#define limit 1200       // 负重上限
#define waterBoxPrice 5  // 水基准价格
#define waterBoxWeight 3 // 水每箱质量
#define foodBoxPrice 10  // 食物基准价格
#define foodBoxWeight 2  // 食物每箱质量

#define maxWater 400 // 水最大携带箱数
#define maxFood 600  // 食物最大携带箱数

#define basicWage 1000     // 基础收益
#define initialMoney 10000 // 初始资金

#define debug cout << "fuck" << endl;

// 状态
#define stay 1
#define walk 2
#define work 3

// 不同天气 水 和 食物 的基础消耗量
unordered_map<char, vector<short>> d{
    {'s', {5, 7}},   // sunny 晴朗 s
    {'m', {10, 10}}, // sandstorm 沙暴 m
    {'h', {8, 6}}    // high temperature 高温 h
};

vector<char> weather{
    ' ',
    'h',
    'h',
    's',
    'm',
    's',
    'h',
    'm',
    's',
    'h',
    'h',
    'm',
    'h',
    's',
    'h',
    'h',
    'h',
    'm',
    'm',
    'h',
    'h',
    's',
    's',
    'h',
    's',
    'm',
    'h',
    's',
    's',
    'h',
    'h'};

// 简化边
vector<pair<int, int>> p{
    {1, 25},
    {25, 24},
    {25, 26},
    {26, 27},
    {24, 23},
    {23, 21},
    {21, 27},
    {21, 9},
    {9, 21},
    {15, 9},
    {9, 15},
    {13, 15},
    {15, 13},
    {12, 13},
    {13, 12}};

// 两两距离
short dis[L + 1][L + 1];

// 点路径
vector<vector<int>> to(L + 1);

// 表示在第i天，水剩j箱，食物剩k箱，到达loc的资金最大为多少
short dp[D + 1][maxWater + 1][maxFood + 1][L + 1];

// 表示该状态访问到与否，防止状态重复入队
char vis[D + 1][maxWater + 1][maxFood + 1][L + 1];

// 状态结构体
struct status
{
    char day;
    short water;
    short food;
    char loc;
} pre[D + 1][maxWater + 1][maxFood + 1][L + 1];

inline bool check(char day, short water, short food, char loc, char state, short &dwater, short &dfood)
{
    if (state == work && loc != 12)
        return false;
    if (weather[day] == 'm' && state == walk)
        return false;
    dwater = water - d[weather[day]][0] * state;
    dfood = food - d[weather[day]][1] * state;
    if (dwater < 0 || dfood < 0)
        return false;
    return true;
}

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    for (auto [x, y] : p)
    {
        to[x].emplace_back(y);
        dis[x][y] = dis[x][y] = 1;
    }
    for (short i = 1; i <= L; ++i)
        dis[i][i] = 0;
    for (short k = 1; k <= L; ++k)
        for (short i = 1; i <= L; ++i)
            for (short j = 1; j <= L; ++j)
                dis[i][j] = min(dis[i][j], (short)(dis[i][k] + dis[k][j]));
    queue<status> q;
    for (short i = 1; i * waterBoxWeight <= limit; ++i)
    {
        for (short j = 1; i * waterBoxWeight + j * foodBoxWeight <= limit; ++j)
        {
            q.push((status){0, i, j, 1});
            dp[0][i][j][1] = initialMoney - i * waterBoxPrice - j * foodBoxPrice;
        }
    }
    // spfa算法
    while (q.size())
    {
        auto [day, water, food, loc] = q.front();
        vis[day][water][food][loc] = 0;
        q.pop();
        short dwater, dfood;
        // 到达村庄，则购买水和食物
        if (loc == 15)
        {
            short money = dp[day][water][food][loc];
            // 此处犯错，把初始化的入队代码复制到此处，未仔细思考边界情况
            // 到村庄可能单买水，单买食物，或者不买，不像起点必须买否则直接死掉
            for (short i = 0; (water + i) * waterBoxWeight <= limit; ++i)
            {
                if (i * waterBoxPrice * 2 > money)
                    break;
                for (short j = 0; (water + i) * waterBoxWeight + (food + j) * foodBoxWeight <= limit; ++j)
                {
                    short les = money - i * waterBoxPrice * 2 - j * foodBoxPrice * 2;
                    if (les < 0)
                        break;
                    if (dp[day][water + i][food + j][loc] < les)
                    {
                        dp[day][water + i][food + j][loc] = les;
                        pre[day][water + i][food + j][loc] = {day, water, food, loc};
                        if (!vis[day][water + i][food + j][loc])
                        {
                            vis[day][water + i][food + j][loc] = 1;
                            q.push((status){day, static_cast<short>(water + i), static_cast<short>(food + j), loc});
                        }
                    }
                }
            }
        }
        // 留在原地
        if (check(day + 1, water, food, loc, stay, dwater, dfood))
        {
            if (day + dis[loc][27] + 1 > 30)
                continue;
            if (dp[day][water][food][loc] <= dp[day + dis[loc][27] + 1][0][0][27])
                continue;
            if (dp[day + 1][dwater][dfood][loc] < dp[day][water][food][loc])
            {
                dp[day + 1][dwater][dfood][loc] = dp[day][water][food][loc];
                pre[day + 1][dwater][dfood][loc] = {day, water, food, loc};
                if (!vis[day + 1][dwater][dfood][loc])
                {
                    vis[day + 1][dwater][dfood][loc] = 1;
                    q.push((status){static_cast<char>(day + 1), dwater, dfood, loc});
                }
            }
        }
        // 行走
        if (check(day + 1, water, food, loc, walk, dwater, dfood))
        {
            for (int t : to[loc])
            {
                if (dis[t][27] >= 30 - day - 1)
                    continue;
                if (dp[day][water][food][loc] <= dp[day + dis[t][27] + 1][0][0][27])
                    continue;
                if (t == 27)
                {
                    // 此处不对多余水和食物作处理，是因为在题设背景下，若已精细规划，不存在剩余
                    dp[day + 1][0][0][t] = dp[day][water][food][loc];
                    pre[day + 1][0][0][t] = {day, water, food, loc};
                    continue;
                }
                if (dp[day + 1][dwater][dfood][t] < dp[day][water][food][loc])
                {
                    dp[day + 1][dwater][dfood][t] = dp[day][water][food][loc];
                    pre[day + 1][dwater][dfood][t] = {day, water, food, loc};
                    if (!vis[day + 1][dwater][dfood][t])
                    {
                        vis[day + 1][dwater][dfood][t] = 1;
                        q.push((status){static_cast<char>(day + 1), dwater, dfood, static_cast<char>(t)});
                    }
                }
            }
        }
        // 挖矿工作
        if (check(day + 1, water, food, loc, work, dwater, dfood))
        {
            if (day + dis[loc][27] + 1 > 30)
                continue;
            if (dp[day][water][food][loc] + basicWage <= dp[day + dis[loc][27] + 1][0][0][27])
                continue;
            if (dp[day + 1][dwater][dfood][loc] < dp[day][water][food][loc] + basicWage)
            {
                dp[day + 1][dwater][dfood][loc] = dp[day][water][food][loc] + basicWage;
                pre[day + 1][dwater][dfood][loc] = {day, water, food, loc};
                if (!vis[day + 1][dwater][dfood][loc])
                {
                    vis[day + 1][dwater][dfood][loc] = 1;
                    q.push((status){static_cast<char>(day + 1), dwater, dfood, loc});
                }
            }
        }
    }
    short ans = 0, pos = 0;
    for (int i = 1; i <= 30; ++i)
    {
        if (ans < dp[i][0][0][27])
        {
            ans = dp[i][0][0][27];
            pos = i;
        }
    }
    char day = pos;
    short water = 0;
    short food = 0;
    char loc = 27;
    vector<status> an;
    an.push_back({day, water, food, loc});
    while (day)
    {
        auto [da, w, f, l] = pre[day][water][food][loc];
        day = da, water = w, food = f, loc = l;
        an.push_back({da, w, f, l});
    }
    reverse(an.begin(), an.end());
    for (auto [da, w, f, l] : an)
    {
        cout << l << ',' << dp[da][w][f][l] << ',' << w << ',' << f << endl;
    }
    return 0;
}