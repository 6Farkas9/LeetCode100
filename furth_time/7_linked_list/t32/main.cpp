#include <iostream>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        unordered_map<Node*, Node*> o2n;
        Node *p = head, *ans = new Node(0);
        Node *q = ans;
        while(p) {
            if(o2n.find(p) == o2n.end()) {
                o2n[p] = new Node(p->val);
            }
            q->next = o2n[p];
            if(!p->random) {
                q->next->random = nullptr;
            }
            else {
                if(o2n.find(p->random) == o2n.end()) {
                    o2n[p->random] = new Node(p->random->val);
                }
                q->next->random = o2n[p->random];
            }
            p = p->next;
            q = q->next;
        }
        q->next = nullptr;
        return ans->next;
    }
};

int main(){
    // ListNode head;
    // ListNode* temp = &head;
    // for(int i = 0; i < head_int.size(); i++){
    //     temp->next = (ListNode*)malloc(sizeof(ListNode));
    //     temp->next->val = head_int[i];
    //     temp->next->next = NULL;
    //     temp = temp->next;
    // }
    // temp = head.next;
    // while(temp){
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // }
    // cout << endl;
    // Solution A;
    // ListNode *res = A.reverseKGroup(head.next, k);
    // while(res){
    //     cout << res->val << " ";
    //     res = res->next;
    // }
}