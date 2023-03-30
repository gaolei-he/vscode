#include <stack>
#include <cstring>
#include <queue>
#include <iostream>
template<typename T>
class mystack1
{
private:
    T* data;
    unsigned int length;
    unsigned int max_len;
public:
    mystack1() {
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
    ~mystack1() {
        if(data) delete[] data;
    }
};
template<typename T>
class myqueue1
{
private:
    int head;
    int tail;
    int max_length;
    T* data;
public:
    myqueue1() {
        head = 0;
        tail = 0;
        max_length = 2;
        data = new T[max_length];
    }
    bool empty() {
        return (tail - head + max_length) % max_length == 0;
    }
    int size() {
        return (tail - head + max_length) % max_length;
    }
    void pop() {
        head = (head + 1 + max_length) % max_length;
    }
    T& front() {
        return data[head];
    }
    void push(T x) {
        if(this->size() + 1 == max_length) {
            T* tmp = new T[max_length << 1];
            
            int l = 0, r = 0;
            while(!this->empty())
            {
                tmp[r++] = this->front();
                this->pop();
            }
            delete[] data;

            data = tmp;
            max_length <<= 1;
            head = l;
            tail = r;
        }
        data[(tail ++ + max_length) % max_length] = x;
        tail %= max_length;
    }
};
using namespace std;
int main()
{
    return 0;
}