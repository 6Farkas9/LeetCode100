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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res;
        ListNode* ptr1 = list1,*ptr2 = list2,*lastone = &res;
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                lastone->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                lastone->next = ptr2;
                ptr2 = ptr2->next;
            }
            lastone = lastone->next;
        }
        while(ptr1){
            lastone->next = ptr1;
            ptr1 = ptr1->next;
            lastone = lastone->next;
        }
        while(ptr2){
            lastone->next = ptr2;
            ptr2 = ptr2->next;
            lastone = lastone->next;
        }
        if(res.next){
            return res.next;
        }
        else{
            return NULL;
        }
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