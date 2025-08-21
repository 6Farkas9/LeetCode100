#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *p = dummy;
        int carry = 0, temp;
        while(p1 && p2){
            temp = carry + p1->val + p2->val;
            carry = temp >= 10 ? 1 : 0;
            temp = temp >= 10 ? temp % 10 : temp;
            p->next = new ListNode(temp);
            p1 = p1->next;
            p2 = p2->next;
            p = p->next;
        }
        if(p2)  p1 = p2;
        while(p1){
            temp = carry + p1->val;
            carry = temp >= 10 ? 1 : 0;
            temp = temp >= 10 ? temp % 10 : temp;
            p->next = new ListNode(temp);
            p1 = p1->next;
            p = p->next;
        }
        if(carry){
            p->next = new ListNode(1);
        }
        return dummy->next;
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