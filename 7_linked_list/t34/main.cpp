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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        if(!num){
            return NULL;
        }
        int gap = 1;
        int left = 0, right;
        while(true){
            right = left + gap;
            if(right >= num){
                if(left == 0){
                    break;
                }
                else{
                    left = 0;
                    gap = gap * 2;
                    continue;
                }
            }
            ListNode dummy;
            ListNode *ptr = &dummy, *left_ptr = lists[left], *right_ptr = lists[right];
            while(left_ptr && right_ptr){
                if(left_ptr->val <= right_ptr->val){
                    ptr->next = left_ptr;
                    left_ptr = left_ptr->next;
                }
                else{
                    ptr->next = right_ptr;
                    right_ptr = right_ptr->next;
                }
                ptr = ptr->next;
            }
            if(right_ptr){
                left_ptr = right_ptr;
            }
            while(left_ptr){
                ptr->next = left_ptr;
                left_ptr = left_ptr->next;
                ptr = ptr->next;
            }
            ptr->next = NULL;
            lists[left] = dummy.next;
            left = left + gap * 2;
            if(left >= num){
                gap = gap * 2;
                left = 0;
            }
        }
        return lists[0];
    }
};

int main(){
    
}