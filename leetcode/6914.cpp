#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> vec;
        ListNode* p = head;
        while (p != nullptr) {
            vec.push_back(p->val);
            p = p->next;
        }
        reverse(vec.begin(), vec.end());
        int op = 0;
        for(auto& x : vec) {
            x = x * 2 + op;
            op = x / 10;
            x %= 10;
        }
        if(op) p = new ListNode(op, head);
        else p = head;
        while (head != nullptr) {
            head->val = vec.back();
            vec.pop_back();
            head = head->next;
        }
        return p;
    }
};