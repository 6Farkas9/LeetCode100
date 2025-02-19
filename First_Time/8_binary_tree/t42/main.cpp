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
        int t_min,t_max;
        return judgeBST(root, t_min, t_max);
    }
private:
    bool judgeBST(TreeNode* root, int & t_min, int & t_max){
        if(!root->left && !root->right){
            t_min = root->val;
            t_max = root->val;
            return true;
        }
        t_min = root->val;
        t_max = root->val;
        int left_min, left_max, right_min, right_max;
        if(root->left){
            if(!judgeBST(root->left, left_min, left_max)){
                return false;
            }
            if(left_max >= root->val){
                return false;
            }
            t_min = left_min;
        }
        if(root->right){
            if(!judgeBST(root->right, right_min, right_max)){
                return false;
            }
            if(right_min <= root->val){
                return false;
            }
            t_max = right_max;
        }
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