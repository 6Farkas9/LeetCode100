#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> head_int = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next)   return nullptr;
        ListNode *p = head->next, *q = head->next->next;
        while(p != q && q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        if(p != q)  return nullptr;
        q = head;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
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
    bool res = A.detectCycle(&head);
    cout << res << endl;
}