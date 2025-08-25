#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return nullptr;
        ListNode *p = headA, *q = headB;
        int a_count = 0, b_count = 0;
        while(p->next) {
            ++a_count;
            p = p->next;
        }
        while(q->next) {
            ++b_count;
            q = q->next;
        }
        if(p != q)  return nullptr;
        p = a_count >= b_count ? headA : headB;
        q = p == headA ? headB : headA;
        int differ = abs(a_count - b_count);
        while(differ) {
            p = p->next;
            --differ;
        }
        while(p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main(){

}