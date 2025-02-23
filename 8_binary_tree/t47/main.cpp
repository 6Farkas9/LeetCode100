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
        int length = inorder.size() - 1;
        for(int i = 0; i <= length; ++i){
            val_to_pos[inorder[i]] = i;
        }
        TreeNode *dummy = new TreeNode();
        build(preorder, inorder, dummy->right, 0, length, 0, length);
        return dummy->right;
    }
private:
    unordered_map<int, int> val_to_pos;
    void build(vector<int>& preorder, vector<int>& inorder, TreeNode* &root, int ps, int pe, int is, int ie){
        cout << ps << "," << pe << "," << is << "," << ie << endl;
        if(ps > pe) return;
        if(ps == pe){
            root = new TreeNode(preorder[ps]);
            return;
        }
        int root_val = preorder[ps];
        int root_pos = val_to_pos[root_val];
        root = new TreeNode(root_val);
        build(preorder, inorder, root->left, ps + 1, ps + root_pos - is, is, root_pos - 1);
        build(preorder, inorder, root->right, ps + root_pos - is + 1, pe, root_pos + 1, ie);
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