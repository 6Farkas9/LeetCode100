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
    bool isValidBST(TreeNode* root) {
        int temp;
        return judgeBST(root, temp, temp);
    }
private:
    bool judgeBST(TreeNode* &root, int &_max, int &_min){
        if(!root->left && !root->right){
            _max = _min = root->val;
            return true;
        }
        int l_max = root->val, l_min = root->val;
        int r_max = root->val, r_min = root->val;
        if(root->left){
            if(!judgeBST(root->left, l_max, l_min)) return false;
            if(root->val <= l_max)  return false;
        }
        if(root->right){
            if(!judgeBST(root->right, r_max, r_min)) return false;
            if(root->val >= r_min)  return false;
        }
        _max = r_max;
        _min = l_min;
        return true;
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