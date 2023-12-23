#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

class Elevator
{
private:
    int floor;
    int direction;
    int times;
    vector<bool> status;
public:
    Elevator(int floor, int direction = 0)
    {
        this->floor = floor;
        this->direction = direction;
        this->times = 1;
        status.resize(7, false);
    }
    bool isUp()
    {
        if(direction == 1)
        {
            bool flag = false;
            for(int i=floor+1;i<=6;i++) if(status[i]) flag = true;
            if(flag) return true;
        }
        else if(direction == -1)
        {
            bool flag = true;
            for(int i=1;i<floor;i++) if(status[i]) flag = false;
            if(flag == false) return false;
            flag = false;
            for(int i=floor+1;i<=6;i++) if(status[i]) flag = true;
            if(flag) return true;
        }
        else
        {
            bool flag = false;
            for(int i=floor+1;i<=6;i++) if(status[i]) return true;
        }
        return false;
    }
    bool isDown()
    {
        if(direction == -1)
        {
            bool flag = false;
            for(int i=1;i<floor;i++) if(status[i]) flag = true;
            if(flag) return true;
        }
        else if(direction == 1)
        {
            bool flag = true;
            for(int i=floor;i<=6;i++) if(status[i]) flag = false;
            if(flag == false) return false;
            flag = false;
            for(int i=1;i<floor;i++) if(status[i]) flag = true;
            if(flag) return true;
        }
        else
        {
            bool flag = false;
            for(int i=1;i<floor;i++) if(status[i]) return true;
        }
        return false;
    }
    int nowLevel() {return floor;}
    int nowTime() {return times;}
    void addDir(int dst) { status[dst] = true;}
    void run()
    {
        times ++;
        if(status[floor]) status[floor] = false;
        if(isUp()) floor ++, direction = 1;
        else if(isDown()) floor --, direction = -1;
        status[floor] = false;
    }
};

int main()
{
    int n; cin >> n;
    queue<pii> querys;
    while(n --)
    {
        int x, y; cin >> x >> y;
        querys.emplace(x, y);
    }
    Elevator elevator(1);
    while(querys.size())
    {
        while(querys.size() and elevator.nowTime() >= querys.front().first)
        {
            elevator.addDir(querys.front().second);
            querys.pop();
        }
        elevator.run();
        cout << elevator.nowLevel() << endl;
    }
    int val = elevator.nowLevel();
    elevator.run();
    while(val != elevator.nowLevel())
    {
        cout << elevator.nowLevel() << endl;
        val = elevator.nowLevel();
        elevator.run();
    }
    
    return 0;
}