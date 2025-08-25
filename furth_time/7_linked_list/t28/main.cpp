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
        ListNode *ans = new ListNode;
        ListNode *p = l1, *q = l2, *h = ans;
        int carry = 0, c_val;
        while(p && q) {
            c_val = p->val + q->val + carry;
            h->next = new ListNode(c_val % 10);
            carry = c_val / 10;
            p = p->next;
            q = q->next;
            h = h->next;
        }
        if(q)   p = q;
        while(p) {
            c_val = p->val + carry;
            h->next = new ListNode(c_val % 10);
            carry = c_val / 10;
            p = p->next;
            h = h->next;
        }
        if(carry) {
            h->next = new ListNode(1);
        }
        return ans->next;
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