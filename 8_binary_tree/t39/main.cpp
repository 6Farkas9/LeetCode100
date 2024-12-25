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
    bool isSymmetric(TreeNode* root) {
        TreeNode *left, *right;
        queue<TreeNode*> left_nodes, right_nodes;
        if(root->left){
            left_nodes.push(root->left);
        }
        if(root->right){
            right_nodes.push(root->right);
        }
        do{
            if(left_nodes.size() != right_nodes.size())
                return false;
            int length = left_nodes.size();
            for(int i = 0; i < length; i++){
                left = left_nodes.front(), right = right_nodes.front();
                if(left->val != right->val)
                    return false;
                if((left->left == NULL ^ right->right == NULL) || (left->right == NULL ^ right->left == NULL))
                    return false;
                left_nodes.pop();
                right_nodes.pop();
                if(left->left){
                    left_nodes.push(left->left);
                    right_nodes.push(right->right);
                }
                if(left->right){
                    left_nodes.push(left->right);
                    right_nodes.push(right->left);
                }
            }
        }while(!left_nodes.empty() && !right_nodes.empty());
        return true;
    }
};