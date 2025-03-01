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
        this->target = targetSum;
        this->presum[0] = 1;
        return dfs(root, 0);
    }
private:
    unordered_map<long long,int> presum;
    long long target;
    int dfs(TreeNode* &root, long long lastsum){
        if(!root)   return 0;
        int ans = 0;
        if(this->presum.find(lastsum - this->target + root->val) != this->presum.end()){
            ans += this->presum[lastsum - this->target + root->val];
        }
        lastsum += root->val;
        ++presum[lastsum];
        ans += dfs(root->left, lastsum);
        ans += dfs(root->right, lastsum);
        --presum[lastsum];
        return ans;
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