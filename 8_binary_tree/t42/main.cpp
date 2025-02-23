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
        TreeNode* dummy = new TreeNode();
        int length = nums.size() - 1;
        createBST(nums, 0, length, dummy->right);
        return dummy->right;
    }
private:
    void createBST(vector<int>& nums, int start, int end, TreeNode* &root){
        if(start > end) return;
        if(start == end){
            root = new TreeNode(nums[start]);
            return;
        }
        int mid = (start + end) / 2;
        root = new TreeNode(nums[mid]);
        createBST(nums, start, mid - 1, root->left);
        createBST(nums, mid + 1, end, root->right);
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