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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int depth = 0;
        if (root == NULL)
            return depth;

        int max_depth = 0;
        deque<TreeNode *> temp_queue;
        temp_queue.push_back(root);

        while (temp_queue.size() != 0)
        {
            root = temp_queue[0];
            temp_queue.pop_front();
            vector<deque<TreeNode *>> left_order;
            vector<deque<TreeNode *>> right_order;
            deque<TreeNode *> temp_left;
            deque<TreeNode *> temp_right;
            int depth_left = 0;
            int depth_right = 0;
            if (root->left != NULL)
            {
                temp_left.push_back(root->left);
                left_order.push_back(temp_left);
                depth_left++;
            }
            if (root->right != NULL)
            {
                temp_right.push_back(root->right);
                right_order.push_back(temp_right);
                depth_right++;
            }

            auto original_root = root;

            do
            {
                deque<TreeNode *> temp;

                while (left_order.size() != 0)
                {
                    // 出队
                    TreeNode *root = left_order.back()[0];
                    if (root->left != NULL)
                        temp.push_back(root->left);
                    if (root->right != NULL)
                        temp.push_back(root->right);
                    left_order.back().pop_front();
                    if (left_order.back().size() == 0)
                    {
                        left_order.pop_back();
                    }
                }
                if (temp.size() != 0)
                {
                    left_order.push_back(temp);
                    depth_left++;
                }
            } while (left_order.size() != 0);

            do
            {
                deque<TreeNode *> temp;

                while (right_order.size() != 0)
                {
                    // 出队
                    TreeNode *root = right_order.back()[0];

                    if (root->left != NULL)
                        temp.push_back(root->left);
                    if (root->right != NULL)
                        temp.push_back(root->right);
                    right_order.back().pop_front();
                    if (right_order.back().size() == 0)
                    {
                        right_order.pop_back();
                    }
                }
                if (temp.size() != 0)
                {
                    right_order.push_back(temp);
                    depth_right++;
                }
            } while (right_order.size() != 0);

            depth = depth_left + depth_right;
            if (depth > max_depth)
                max_depth = depth;
            if (root->left != NULL)
                temp_queue.push_back(root->left);
            if (root->right != NULL)
                temp_queue.push_back(root->right);
        }
        return max_depth;
    }
};