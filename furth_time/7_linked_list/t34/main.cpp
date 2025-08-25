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
        int length = lists.size();
        if(!length) return nullptr;
        int c_pos, l1, l2;
        ListNode *dummy = new ListNode, *p, *q, *c;
        while(length > 1) {
            c_pos = 0;
            l1 = 0, l2 = 1;
            while(l1 < length && l2 < length) {
                cout << c_pos << "," << l1 << "," << l2 << endl;
                p = lists[l1];
                q = lists[l2];
                c = dummy;
                c->next = nullptr;
                while(p && q) {
                    if(p->val <= q->val) {
                        c->next = p;
                        p = p->next;
                    }
                    else {
                        c->next = q;
                        q = q->next;
                    }
                    c = c->next;
                }
                if(q)   p = q;
                while(p) {
                    c->next = p;
                    p = p->next;
                    c = c->next;
                }
                lists[c_pos] = dummy->next;
                ++c_pos;
                l1 = c_pos * 2;
                l2 = c_pos * 2 + 1;
            }
            if(l1 < length) {
                lists[c_pos] = lists[l1];
            }
            length = (length + 1) / 2;
        }
        return lists[0];
    }
};

int main(){
    
}