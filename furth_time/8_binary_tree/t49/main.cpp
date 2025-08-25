#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        find(root, p, q, ans);
        return ans;
    }
private:
    bool find(TreeNode* &root, TreeNode* &p, TreeNode* &q, TreeNode* &ans) {
        if(!root)   return false;
        int count = 0;
        if(root == p || root == q)  ++count;
        if(find(root->left, p, q, ans)) ++count;
        if(find(root->right,p, q, ans)) ++count;
        if(count == 1)  return true;
        else {
            if(count == 2)  ans = root;
            return false;
        }
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