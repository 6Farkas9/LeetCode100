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
        int cl, ll = length;
        cl = ll % 2 == 1 ? ll / 2 + 1 : ll / 2;
        ListNode *dummy = new ListNode(), *p, *q, *r;
        while(ll > 1){
            for(int i = 0; i < cl; ++i){
                if(i*2 + 1 >= ll)  lists[i] = lists[i*2];
                else{
                    dummy->next = nullptr;
                    p = lists[i*2], q = lists[i*2+1], r = dummy;
                    while(p && q){
                        if(p->val <= q->val){
                            r->next = p;
                            p = p->next;
                        }
                        else{
                            r->next = q;
                            q = q->next;
                        }
                        r = r->next;
                    }
                    while(p){
                        r->next = p;
                        p = p->next;
                        r = r->next;
                    }
                    while(q){
                        r->next = q;
                        q = q->next;
                        r = r->next;
                    }
                    lists[i] = dummy->next;
                }
            }
            ll = cl;
            cl = ll % 2 == 1 ? ll / 2 + 1 : ll / 2;
        }
        return lists[0];
    }
};

int main(){
    
}