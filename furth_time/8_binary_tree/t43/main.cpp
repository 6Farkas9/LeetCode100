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
        if(!root)   return true;
        int _min, _max;
        return judgeBST(root, _min, _max);
    }
private:
    bool judgeBST(TreeNode* root, int &_min, int &_max) {
        int lmax, lmin, rmax, rmin;
        if(!root->left) {
            lmax = lmin = root->val;
        }
        else {
            if(!judgeBST(root->left, lmin, lmax))   return false;
            if(root->val <= lmax)   return false;
        }
        if(!root->right) {
            rmax = rmin = root->val;
        }
        else {
            if(!judgeBST(root->right, rmin, rmax))  return false;
            if(root->val >= rmin)   return false;
        }
        _min = lmin;
        _max = rmax;
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