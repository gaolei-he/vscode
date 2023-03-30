#include <iostream>
using namespace std;
typedef int Elem;
struct Node
{
    Elem data;
    Node* next;
};
void init(Node*& stk)
{
    stk->next = nullptr;
}
void push(Node*& stk, Elem data)
{
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = stk->next;
    stk->next = tmp;
}
Elem top(Node*& stk)
{
    return stk->data;
}
void pop(Node*& stk)
{
    Node* tmp = stk->next;
    delete stk;
    stk = tmp;
}
bool empty(Node*& stk)
{
    return stk->next == nullptr;
}