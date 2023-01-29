#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    void insert(int num){
        if(a2.size()!=0&&a1.size()==0) a1.push(num);
        else a2.push(num);
        if(a1.size()&&a2.top()>a1.top())
        {
            int tmp2 = a2.top();
            int tmp1 = a1.top();
            a1.pop(), a2.pop();
            a1.push(tmp2);
            a2.push(tmp1);
        }
        if(a2.size()-a1.size()>1)
        {
            int tmp = a2.top();
            a2.pop();
            a1.push(tmp);
        }
        
    }
    priority_queue<int, vector<int>, greater<int>> a1;
    priority_queue<int, vector<int>, less<int>> a2;

    double getMedian(){
        if(a2.size()>a1.size()) return a2.top()*1.0;
        else return (a1.top()+a2.top())/2.0;
        
    }
};

int main()
{
    int n;
    cin >> n;
    Solution a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.insert(x);
        cout << a.getMedian() << endl;
    }
    return 0;
}