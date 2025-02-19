#include <iostream>
#include <vector>

using namespace std;

vector<int> head_int = {1,2,3,4,5};
int k = 5;

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
        if(!head || k == 1){
            return head;
        }
        ListNode *iter1, *iter2, *c_start = head, *c_end, *pre_start;
        ListNode dummy;
        dummy.next = head;
        pre_start = &dummy;
        while(c_start){
            int i = 0;
            c_end = c_start;
            for(; i < k; i++){
                if(!c_end)
                    return dummy.next;
                c_end = c_end->next;
            }
            iter1 = c_start;
            iter2 = c_start->next;
            while(iter2 != c_end){
                c_start->next = iter2->next;
                iter2->next = iter1;
                iter1 = iter2;
                iter2 = c_start->next;
            }
            pre_start->next = iter1;
            c_start->next = c_end;
            pre_start = c_start;
            c_start = c_end;
        }
        return dummy.next;
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
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}