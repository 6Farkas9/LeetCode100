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
        this->pre_sum[0] = 1;
        return dfsSum(root,0,targetSum);
    }
private:
    unordered_map<long long, int> pre_sum;
    int dfsSum(TreeNode *root, long long last_sum, int targetSum){
        if(!root){
            return 0;
        }
        int res = 0;
        long long current_sum = last_sum + root->val;
        long long current_target = current_sum - targetSum;
        if(this->pre_sum.find(current_target) != this->pre_sum.end()){
            res += this->pre_sum[current_target];
        }
        pre_sum[current_sum]++;
        res += dfsSum(root->left, current_sum, targetSum);
        res += dfsSum(root->right, current_sum, targetSum);
        pre_sum[current_sum]--;
        return res;
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