#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> nums = {-10,-3,0,5,9};

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        TreeNode *res = NULL;
        createBSF(nums, 0, length - 1, res);
        return res;
    }
private:
    void createBSF(vector<int> & nums, int left, int right, TreeNode* &root){
        if(left > right){
            return;
        }
        int mid = (left + right) / 2;
        root = new TreeNode(nums[mid]);
        createBSF(nums, left, mid - 1, root->left);
        createBSF(nums, mid + 1, right, root->right);
    }
};

int main(){
    Solution A;
    TreeNode *res = A.sortedArrayToBST(nums);
    if(res)
        cout << res->val << endl;
    else
        cout << "?" << endl;
}