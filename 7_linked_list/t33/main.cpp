#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> head_int = {5, 6, 2, 7, 9, 3, 1, 6, 8, 10, 23};

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
    ListNode *sortList(ListNode *head)
    {
        // 当且仅当前指head，末尾指向null的时候才算结束
        // 归并长度从2开始，每次*2
        // 可以写一个函数使其完成从start到end的归并
        int length = 1;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *start, *mid, *end, *currenthead;
        while (true)
        {
            start = dummy->next;
            currenthead = dummy;
            while (true)
            {
                // 找mid
                mid = start;
                bool no_need_sort = false;
                for (int i = 0; i < length; ++i)
                {
                    if (!mid)
                    {
                        if (start == dummy->next)
                            return dummy->next;
                        no_need_sort = true;
                        break;
                    }
                    mid = mid->next;
                }
                if (no_need_sort)
                    break;
                // 找end
                end = mid;
                for (int i = 0; i < length && end; ++i)
                {
                    end = end->next;
                }
                ListNode *temp = end;
                // currenthead->next = merge(start, mid, end);

                ListNode *p = start, *q = mid, *r = currenthead;
                while (p != mid && q != end)
                {
                    if (p->val <= q->val)
                    {
                        r->next = p;
                        p = p->next;
                    }
                    else
                    {
                        r->next = q;
                        q = q->next;
                    }
                    r = r->next;
                }
                while (p != mid)
                {
                    r->next = p;
                    p = p->next;
                    r = r->next;
                }
                while (q != end)
                {
                    r->next = q;
                    q = q->next;
                    r = r->next;
                }

                start = end;
                currenthead = r;
                currenthead->next = start;
            }
            length = length * 2;
        }
    }

// private:
//     // 令mid是第二列的开始,end是下一次的开始
//     ListNode *merge(ListNode *&start, ListNode *&mid, ListNode *&end)
//     {
//         ListNode *dummy = new ListNode();
//         ListNode *p = start, *q = mid, *r = dummy;
//         while (p != mid && q != end)
//         {
//             if (p->val <= q->val)
//             {
//                 r->next = p;
//                 p = p->next;
//             }
//             else
//             {
//                 r->next = q;
//                 q = q->next;
//             }
//             r = r->next;
//         }
//         while (p != mid)
//         {
//             r->next = p;
//             p = p->next;
//             r = r->next;
//         }
//         while (q != end)
//         {
//             r->next = q;
//             q = q->next;
//             r = r->next;
//         }
//         end = r;
//         return dummy->next;
//     }
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