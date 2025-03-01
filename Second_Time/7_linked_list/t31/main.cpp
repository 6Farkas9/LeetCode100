#include <iostream>
#include <vector>

using namespace std;

vector<int> head_int = {1,2,3,4,5};
int k = 2;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(), *p, *q, *temp;
        dummy->next = head;
        p = dummy, q = head;
        while(q){
            for(int i = 0; i < k; ++i){
                if(!q)  return dummy->next;
                q = q->next;
            }
            temp = p->next;
            p->next = reverseListTo(p->next, q);
            p = temp;
        }
        return dummy->next;
    }
private:
    ListNode* reverseListTo(ListNode* head, ListNode* _end) {
        if(!head || !head->next)   return head;
        ListNode *pc = head, *pn = head->next;
        while(pn != _end){
            head->next = pn->next;
            pn->next = pc;
            pc = pn;
            pn = head->next;
        }
        head->next = _end;
        return pc;
    }
};

int main(){
    ListNode head;
    ListNode* temp = &head;
    for(int i = 0; i < head_int.size(); i++){
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = head_int[i];
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head.next;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    Solution A;
    ListNode *res = A.reverseKGroup(head.next, k);
    // ListNode *res = A.reverseListTo(head.next, nullptr);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}