#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        TreeNode *ptr = NULL;
        queue<TreeNode*> lastnodes;
        lastnodes.push(root);
        do{
            int length = lastnodes.size();
            for(int i = 0; i < length; i++){
                ptr = lastnodes.front();
                lastnodes.pop();
                if(ptr->left)
                    lastnodes.push(ptr->left);
                if(ptr->right)
                    lastnodes.push(ptr->right);
                if(i == length - 1)
                    res.push_back(ptr->val);
            }
        }while(!lastnodes.empty());
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