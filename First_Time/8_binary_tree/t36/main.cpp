#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<TreeNode*> lastnodes;
        TreeNode* ptr = root;
        while(true){
            while(ptr->left){
                lastnodes.push(ptr);
                ptr = ptr->left;
            }
            res.push_back(ptr->val);
            if(ptr->right){
                ptr = ptr->right;
            }
            else{
                while(!lastnodes.empty() && !ptr->right){
                    ptr = lastnodes.top();
                    res.push_back(ptr->val);
                    lastnodes.pop();
                }
                if(ptr->right){
                    ptr = ptr->right;
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};