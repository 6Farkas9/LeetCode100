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

vector<int> head_int = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode *q = head;
        ListNode *p = head, *n = head->next, *temp = head->next;
        while(q->next && q->next->next) {
            q = q->next->next;
            temp = n->next;
            n->next = p;
            p = n;
            n = temp;
        }
        if(!q->next) {
            p = p->next;
        }
        q = temp;
        head->next = nullptr;
        bool ans = true;
        while(p && q && ans) {
            ans = (p->val == q->val);
            p = p->next;
            q = q->next;
        }
        return ans;
    }
};

int main(){
    ListNode head;
    ListNode* temp = &head;
    for(int i = 0; i < head_int.size(); i++){
        temp->val = head_int[i];
        if(i != head_int.size() - 1){
            temp->next = new ListNode;
            temp = temp->next;
        }
        else{
            temp->next = NULL;
        }
    }
    temp = &head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    Solution A;
    bool res = A.isPalindrome(&head);
    cout << res << endl;
}