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
        if(!head)
            return head;
        unordered_map<Node*,Node*> relation;
        Node *res = (Node*)malloc(sizeof(Node));
        res->val = head->val;
        res->next = NULL;
        res->random = NULL;
        Node *ptr_orign = head->next, *ptr_res = res;
        relation[head] = res;
        while(ptr_orign){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->val = ptr_orign->val;
            temp->next = NULL;
            temp->random = NULL;
            ptr_res->next = temp;
            ptr_res = ptr_res->next;
            relation[ptr_orign] = ptr_res;
            ptr_orign = ptr_orign->next;
        }
        ptr_orign = head;
        ptr_res = res;
        while(ptr_orign){
            if(ptr_orign->random)
                ptr_res->random = relation[ptr_orign->random];
            ptr_res = ptr_res->next;
            ptr_orign = ptr_orign->next;
        }
        return res;
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