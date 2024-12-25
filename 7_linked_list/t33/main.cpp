#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> head_int = {5,6,2,7,9,3,1,6,8,10,23};

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode dummy;
        dummy.next = head;
        ListNode *pre_start, *start_left, *start_right, *end_left, *end_right;
        int current_gap = 1;
        pre_start = &dummy;
        while(true){
            start_left = pre_start->next;
            start_right = start_left;
            int i = 0;
            for(i = 0; i < current_gap && start_right; i++){
                start_right = start_right->next;
            }
            if(!start_right){
                if(pre_start == &dummy){
                    break;
                }
                else{
                    current_gap = current_gap * 2;
                    pre_start = &dummy;
                    continue;
                }
            }
            end_left = start_right;
            end_right = start_right;
            for(i = 0; i < current_gap && end_right; i++){
                end_right = end_right->next;
            }
            while(start_left != end_left && start_right != end_right){
                if(start_left->val <= start_right->val){
                    pre_start->next = start_left;
                    start_left = start_left->next;
                }
                else{
                    pre_start->next = start_right;
                    start_right = start_right->next;
                }
                pre_start = pre_start->next;
            }
            while(start_left != end_left){
                pre_start->next = start_left;
                start_left = start_left->next;
                pre_start = pre_start->next;
            }
            while(start_right != end_right){
                pre_start->next = start_right;
                start_right = start_right->next;
                pre_start = pre_start->next;
            }
            pre_start->next = end_right;
            if(!end_right){
                current_gap = current_gap * 2;
                pre_start = &dummy;
            }
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
    ListNode *res = A.sortList(head.next);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}