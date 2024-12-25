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

vector<int> head_int = {2};

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
        if(!head)
            return false;
        int num = 0;
        ListNode* temp_head = head;
        while(temp_head){
            num++;
            temp_head = temp_head->next;
        }
        int num_half = num / 2;
        temp_head = head;
        ListNode* temp_tail = head->next;
        for(int i = 1; i < num_half; i++){
            head->next = temp_tail->next;
            temp_tail->next = temp_head;
            temp_head = temp_tail;
            temp_tail = head->next;
            head->next = NULL;
        }
        if(num % 2 == 1 && num != 1)
            temp_tail = temp_tail->next;
        while(temp_tail != NULL){
            if(temp_head->val != temp_tail->val)
                return false;
            temp_head = temp_head->next;
            temp_tail = temp_tail->next;
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
    Solution A;
    bool res = A.isPalindrome(&head);
    cout << res << endl;
}