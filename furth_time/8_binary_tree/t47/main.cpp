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
        int length = preorder.size() - 1;
        unordered_map<int, int> inval2pos;
        for(int i = 0; i <= length; ++i) {
            inval2pos[inorder[i]] = i;
        }
        return build(preorder, 0, length, 0, inval2pos);
    }
private:
    TreeNode* build(vector<int>& preorder, int ps, int pe, int is, unordered_map<int, int> &inval2pos) {
        if(ps > pe) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left = build(preorder, ps + 1, inval2pos[preorder[ps]] - is + ps, is, inval2pos);
        root->right =  build(preorder, inval2pos[preorder[ps]] - is + ps + 1, pe, inval2pos[preorder[ps]] + 1, inval2pos);
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