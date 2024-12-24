#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* slow_ptr = head, *fast_ptr = head;
        do{
            if(slow_ptr->next && fast_ptr->next && fast_ptr->next->next){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
            }
            else{
                return NULL;
            }
        }while(slow_ptr != fast_ptr);
        fast_ptr = head;
        while(fast_ptr != slow_ptr){
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        return fast_ptr;
    }
};

int main(){
    // ListNode head;
    // ListNode* temp = &head;
    // for(int i = 0; i < head_int.size(); i++){
    //     temp->val = head_int[i];
    //     if(i != head_int.size() - 1){
    //         temp->next = new ListNode;
    //         temp = temp->next;
    //     }
    //     else{
    //         temp->next = NULL;
    //     }
    // }
    // Solution A;
    // bool res = A.isPalindrome(&head);
    // cout << res << endl;
}