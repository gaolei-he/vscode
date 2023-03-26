#include <stack>
#include <cstring>
#include <queue>
#include <iostream>
template<typename T>
class mystack
{
private:
    T* data;
    unsigned int length;
    unsigned int max_len;
public:
    mystack() {
        this->length = 0;
        this->max_len = 0;
        data = nullptr;
    }
    void push(T x) {
        if(length >= max_len) {
            T* tmp = data;
            max_len = max_len ? (max_len<<1):(1);
            data = new T[max_len];
            if(tmp) {
                // memcpy(data, tmp, sizeof(tmp));
                for (int i = 0; i < length; i++)
                    data[i] = tmp[i];
                delete[] tmp;
            }
        }
        data[length++] = x;
    }
    void pop() {
        if(length) --length;
    }
    bool empty() {
        return length == 0;
    }
    T& top() {
        return data[length - 1];
    }
    unsigned int size() {
        return length;
    }
    ~mystack() {
        if(data) delete[] data;
    }
};
int main()
{
    std::stack<int> s;
    mystack<std::string> stk;
    int n; std::cin >> n;
    for(int i=0;i<n;i++)
    {
        stk.push(std::to_string(i));
        std::cout << stk.top() << std::endl;
    }
    return 0;
}