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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while(n--){
            q = q->next;
        }
        if(!q)  return head->next;
        while(q->next){
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
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