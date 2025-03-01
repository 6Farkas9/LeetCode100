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
        vector<int> ans;
        if(!root)   return ans;
        queue<TreeNode*> nodes;
        TreeNode* p;
        int num = 1, cnum = 0;
        nodes.push(root);
        while(!nodes.empty()){
            for(int i = 0; i < num; ++i){
                p = nodes.front();
                if(p->left){
                    nodes.push(p->left);
                    ++cnum;
                }
                if(p->right){
                    nodes.push(p->right);
                    ++cnum;
                }
                nodes.pop();
            }
            ans.push_back(p->val);
            num = cnum;
            cnum = 0;
        }
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