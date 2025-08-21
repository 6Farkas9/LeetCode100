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
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
private:
    int dfs(TreeNode* root, int &ans){
        if(!root)   return 0;
        int l_ans = dfs(root->left, ans);
        int r_ans = dfs(root->right, ans);
        int c_ans = root->val + l_ans + r_ans;
        ans = max(ans, c_ans);
        return max(0, root->val + max(l_ans, r_ans));
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