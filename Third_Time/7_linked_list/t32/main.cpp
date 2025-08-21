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
        unordered_map<Node*, Node*> created;
        Node *p = head;
        Node *ans = new Node(0), *last = ans;
        while(p){
            if(created.find(p) != created.end()){
                last->next = created[p];
            }
            else{
                last->next = new Node(p->val);
                created[p] = last->next;
            }
            if(!p->random){
                last->next->random = nullptr;
            }
            else if(created.find(p->random) != created.end()){
                last->next->random = created[p->random];
            }
            else{
                last->next->random = new Node(p->random->val);
                created[p->random] = last->next->random;
            }
            last = last->next;
            p = p->next;
        }
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