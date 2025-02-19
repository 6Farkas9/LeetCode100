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
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        TreeNode *last_end = root, *ptr = root, *next_end, *temp;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int layer = 0;
        while(!nodes.empty()){
            res.push_back(vector<int>());
            while(true){
                temp = nodes.front();
                nodes.pop();
                res[layer].push_back(temp->val);
                if(temp->left){
                    next_end = temp->left;
                    nodes.push(temp->left);
                }
                if(temp->right){
                    next_end = temp->right;
                    nodes.push(temp->right);
                }
                if(temp == last_end){
                    last_end = next_end;
                    break;
                }
            }
            layer++;
        }
        return res;
    }
};