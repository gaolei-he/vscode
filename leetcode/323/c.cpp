#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Allocator {
public:
    vector<int> a;

    Allocator(int n) {
        a.resize(n);
        for(auto& i:a) i = 0;
    }
    
    int allocate(int size, int mID) {
        for (int i = 0; i < a.size(); i++)
        {
            int cnt = 0, j;
            for(j=i;j < a.size();j++)
            {
                if(a[j] == 0) cnt ++;
                else break;
            }
            if(cnt >= size) {for(int k=i;k-i<size && k < a.size();k++) a[k] = mID; return i;}
            else i = j - 1;
        }
        return -1;
        
    }
    
    int free(int mID) {
        int res = 0;
        for(auto i:a) if(i == mID) res ++;
        return res;
    }
};

int main()
{

    return 0;
}