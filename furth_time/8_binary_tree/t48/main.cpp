#include <iostream>
#include <vector>
#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long, int> presum;
        ++presum[0];
        long lastsum = 0;
        deepSearch(root, targetSum, lastsum, presum, ans);
        return ans;
    }
private:
    void deepSearch(TreeNode* root, int &targetSum, long &lastsum, unordered_map<long, int> &presum, int &ans) {
        if(!root)   return;
        ans += presum[lastsum - (targetSum - root->val)];
        lastsum += root->val;
        ++presum[lastsum];
        deepSearch(root->left, targetSum, lastsum, presum, ans);
        deepSearch(root->right, targetSum, lastsum, presum, ans);
        --presum[lastsum];
        lastsum -= root->val;
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