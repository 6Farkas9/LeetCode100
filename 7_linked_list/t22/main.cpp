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
        int num_a = 0,num_b = 0;
        ListNode* tail_A = headA;
        while(tail_A->next != NULL){
            tail_A = tail_A->next;
            num_a++;
        }
        ListNode* tail_B = headB;
        while(tail_B->next != NULL){
            tail_B = tail_B->next;
            num_b++;
        }
        if(tail_A == tail_B){
            tail_A = headA;
            tail_B = headB;
            while(num_a > num_b){
                tail_A = tail_A->next;
                num_a--;
            }
            while(num_a < num_b){
                tail_B = tail_B->next;
                num_b--;
            }
            while(tail_A != tail_B){
                tail_A = tail_A->next;
                tail_B = tail_B->next;
            }
            return tail_A;
        }
        else{
            return NULL;
        }
    }
};

int main(){

}