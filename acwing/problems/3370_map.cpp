#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

map<string, int> id = {
    {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2},
    {"Dragon", 3}, {"Snake", 4}, {"Horse", 5},
    {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8},
    {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
};
int main()
{
    int n;
    cin >> n;
    map<string, int> p;
    p["Bessie"] = 0;
    string tmp;
    tmp = "Ox";
    while(n--)
    {
        string s[8];
        for(int i=0;i<8;i++) cin >> s[i];
        if(s[3]=="previous")
        {
            int x = p[s[7]], y = id[s[4]];//x老牛出生年，y新牛属性
            int r = p[s[7]];//老牛属性
            while(r<0) r += 12;

            p[s[0]] = x - (r - y + 12) % 12;
            if(!(r-y)) p[s[0]] -= 12;
        }
        else
        {
            int x = p[s[7]], y = id[s[4]];
            int r = x;
            while(r<0) r += 12;
            p[s[0]] = x + (y-r+12)%12;
            if(!(y-r)) p[s[0]] += 12;
        }
        tmp = s[4];
    }
    cout << abs(p["Elsie"]);

    return 0;
}