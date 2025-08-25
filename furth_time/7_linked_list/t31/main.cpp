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
        if(k == 1 || !head->next)   return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *h = dummy, *tail = head, *p, *q, *temp;
        while(true) {
            int count = k;
            while(count && tail){
                tail = tail->next;
                count--;
            }
            if(count)   break;
            p = h->next, q = h->next->next;
            while(q != tail) {
                temp = q->next;
                q->next = p;
                p = q;
                q = temp;
            }
            h->next->next = tail;
            q = h->next;
            h->next = p;
            h = q;
        }
        return dummy->next;
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