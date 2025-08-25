#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        deque<TreeNode*> nodes;
        TreeNode* lastend = root, *p;
        ans.emplace_back(vector<int>());
        nodes.push_back(root);
        while(!nodes.empty()) {
            p = nodes.front();
            nodes.pop_front();
            ans.back().emplace_back(p->val);
            if(p->left)
                nodes.push_back(p->left);
            if(p->right)
                nodes.push_back(p->right);
            if(p == lastend && !nodes.empty()) {
                lastend = nodes.back();
                ans.emplace_back(vector<int>());
            }
        }
        return ans;
    }
};