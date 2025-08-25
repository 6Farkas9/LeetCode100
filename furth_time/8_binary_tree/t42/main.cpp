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
        int length = nums.size() - 1;
        return createBinarySearchTree(nums, 0, length);
    }
private:
    TreeNode* createBinarySearchTree(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        if(start == end)    return new TreeNode(nums[start]);
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = createBinarySearchTree(nums, start, mid - 1);
        root->right = createBinarySearchTree(nums, mid + 1, end);
        return root;
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