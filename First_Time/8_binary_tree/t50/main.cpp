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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return this->max_sum;
    }
private:
    int max_sum = INT_MIN;
    int dfs(TreeNode* root){
        if(!root->left && !root->right){
            if(root->val > this->max_sum) this->max_sum = root->val;
            return root->val;
        }
        int left_res = -1, right_res = -1;
        if(root->left)  left_res = dfs(root->left);
        if(root->right) right_res = dfs(root->right);
        int res = root->val;
        if(left_res > 0)    res += left_res;
        if(right_res > 0)   res += right_res;
        if(res > this->max_sum) this->max_sum = res;
        int plus_sum = max(left_res, right_res);
        if(plus_sum > 0) return root->val + plus_sum;
        else return root->val;
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