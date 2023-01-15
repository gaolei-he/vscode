#include <iostream>
#include <map>
using namespace std;
map<char, string> mp = {
    {'q', "1 1"}, {'w', "1 2"}, {'e', "1 3"}, {'r', "1 4"}, {'t', "1 5"}, {'y', "1 6"}, {'u', "1 7"}, {'i', "1 8"}, {'o', "1 9"}, {'p', "1 10"}, 
    {'a', "2 1"}, {'s', "2 2"}, {'d', "2 3"}, {'f', "2 4"}, {'g', "2 5"}, {'h', "2 6"}, {'j', "2 7"}, {'k', "2 8"}, {'l', "2 9"}, 
    {'z', "3 2"}, {'x', "3 3"}, {'c', "3 4"}, {'v', "3 5"}, {'b', "3 6"}, {'n', "3 7"}, {'m', "3 8"}, 
};
char str[1010];
int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        scanf("%s", str);
        for(int i=0;str[i];i++)
        {
            if(str[i] >= 97) cout << mp[str[i]] << endl;
            else
            {
                cout << "3 1 ";
                str[i] += 32;
                cout << mp[str[i]] << endl;
            }
        }
    }
    
    return 0;
}