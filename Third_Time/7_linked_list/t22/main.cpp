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
        int a_l = 1, b_l = 1;
        ListNode *a_ptr = headA, *b_ptr = headB;
        while(a_ptr->next){
            ++a_l;
            a_ptr = a_ptr->next;
        }
        while(b_ptr->next){
            ++b_l;
            b_ptr = b_ptr->next;
        }
        if(a_ptr != b_ptr)  return nullptr;
        a_ptr = headA, b_ptr = headB;
        if(a_l > b_l){
            while(a_l > b_l){
                --a_l;
                a_ptr = a_ptr->next;
            }
        }
        else if(a_l < b_l){
            while(a_l < b_l){
                --b_l;
                b_ptr = b_ptr->next;
            }
        }
        while(a_ptr != b_ptr){
            a_ptr = a_ptr->next;
            b_ptr = b_ptr->next;
        }
        return  a_ptr;
    }
};

int main(){

}