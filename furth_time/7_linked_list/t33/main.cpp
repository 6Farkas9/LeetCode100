#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> head_int = {};

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next)    return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *start1, *start2, *end1, *end2, *c;
        int length = 1, c_length;
        bool unsorted = true;
        while(unsorted) {
            c = dummy;
            while(true) {
                start1 = end1 = c->next;
                c_length = length;
                while(c_length && end1) {
                    end1 = end1->next;
                    --c_length;
                }
                if(!end1) {
                    if(start1 == dummy->next)
                        unsorted = false;
                    break;
                }
                start2 = end2 = end1;
                c_length = length;
                while(c_length && end2) {
                    end2 = end2->next;
                    --c_length;
                }
                while(start1 != end1 && start2 != end2) {
                    if(start1->val <= start2->val) {
                        c->next = start1;
                        start1 = start1->next;
                    }
                    else {
                        c->next = start2;
                        start2 = start2->next;
                    }
                    c = c->next;
                }
                if(start2 != end2){
                    start1 = start2;
                    end1 = end2;
                }  
                while(start1 != end1) {
                    c->next = start1;
                    start1 =  start1->next;
                    c = c->next;
                }
                c->next = end2;
            }
            length *= 2;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode head;
    ListNode *temp = &head;
    for (int i = 0; i < head_int.size(); i++)
    {
        temp->next = (ListNode *)malloc(sizeof(ListNode));
        temp->next->val = head_int[i];
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head.next;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    Solution A;
    ListNode *res = A.sortList(head.next);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
}

// if(!head || !head->next)    return head;
//         vector<ListNode*> store;
//         ListNode *p = head;
//         while(p){
//             store.emplace_back(p);
//             p = p->next;
//         }
//         sort(store.begin(), store.end(),[](ListNode* const& a, ListNode* const & b){
//             return  a->val < b->val;
//         });
//         head = p = store[0];
//         int n = store.size();
//         for(int i = 1; i < n; ++i){
//             p->next = store[i];
//             p = p->next;
//         }
//         p->next = nullptr;
//         return head;