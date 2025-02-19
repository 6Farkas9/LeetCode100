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
        ListNode res;
        ListNode *ptr1 = l1, *ptr2 = l2, *lastone = &res, *temp_ptr = NULL;
        int fromlast = 0,temp;
        while(ptr1 && ptr2){
            temp = ptr1->val + ptr2->val + fromlast;
            if(temp >= 10){
                fromlast = 1;
            }
            else{
                fromlast = 0;
            }
            temp = temp % 10;
            ptr1->val = temp;
            lastone->next = ptr1;
            lastone = lastone->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1)
            temp_ptr = ptr1;
        if(ptr2){
            temp_ptr = ptr2;
        }
        while(temp_ptr){
            temp = temp_ptr->val + fromlast;
            if(temp >= 10){
                fromlast = 1;
            }
            else{
                fromlast = 0;
            }
            temp = temp % 10;
            temp_ptr->val = temp;
            lastone->next = temp_ptr;
            lastone = lastone->next;
            temp_ptr = temp_ptr->next;
        }
        if(fromlast){
            l2->val = 1;
            l2->next = NULL;
            lastone->next = l2;
        }
        return res.next;
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