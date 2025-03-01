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
        TreeNode* p;
        queue<TreeNode*> level;
        level.push(root);
        int num = 1, cnum = 0;
        while(!level.empty()){
            vector<int> current;
            for(int i = 0; i < num; ++i){
                p = level.front();
                current.emplace_back(p->val);
                if(p->left){
                    level.push(p->left);
                    ++cnum;
                }
                if(p->right){
                    level.push(p->right);
                    ++cnum;
                }
                level.pop();
            }
            ans.push_back(current);
            num = cnum;
            cnum = 0;
        }
        return ans;
    }
};