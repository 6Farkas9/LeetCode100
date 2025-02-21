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

vector<int> head_int = {1,2,2,1};

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
        if(!head->next->next){
            return head->val == head->next->val;
        }
        ListNode *fast = head, *slow = head, *slow_next = head->next;
        while(true){
            if(!fast->next){
                fast = slow_next;
                slow = slow->next;
                break;
            }
            else if(!fast->next->next){
                fast = slow_next;
                break;
            }
            else{
                fast = fast->next->next;
                head->next = slow_next->next;
                slow_next->next = slow;
                slow = slow_next;
                slow_next = head->next;
            }
        }
        while(fast){
            if(slow->val != fast->val)  return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
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