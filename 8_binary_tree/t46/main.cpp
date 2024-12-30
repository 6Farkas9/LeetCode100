#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        for(int i = 0; i < length; i++)
            this->in_pos[inorder[i]] = i;
        return build(preorder, inorder, 0, length - 1, 0, length - 1);
    }
private:
    unordered_map<int,int> in_pos;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end){
        if(pre_start == pre_end){
            return new TreeNode(preorder[pre_start]);
        }
        int root_val = preorder[pre_start];
        TreeNode *root = new TreeNode(root_val);
        int in_root_pos = this->in_pos[root_val];
        int length = in_root_pos - in_start;
        if(in_root_pos != in_start){
            root->left = build(preorder, inorder, pre_start + 1, pre_start + length, in_start, in_root_pos - 1);
        }
        if(in_root_pos != in_end){
            root->right = build(preorder, inorder, pre_start + length + 1, pre_end, in_root_pos + 1, in_end);
        }
        return root;
    }
};

int main(){
    // Solution A;
    // TreeNode *res = A.sortedArrayToBST(nums);
    // if(res)
    //     cout << res->val << endl;
    // else
    //     cout << "?" << endl;
}