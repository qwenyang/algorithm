#include <stdio.h>

/* 题目地址： https://leetcode-cn.com/problems/balanced-binary-tree/
    给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/
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

/*
    深度分析：由底向上递归，主要是要求左右子树的深度，且左右子树同时都是二叉平衡树
    getDepth：返回深度，当然深度值=-1表示是非二叉平衡树，
*/

class Solution {
public:
    int getDepth(TreeNode* node, const int depth) {
        if(node == NULL) {
            return depth;
        }
        int left_depth = depth, right_depth = depth;
        if(node->left != NULL) {
            left_depth = getDepth(node->left, depth+1);
            if(left_depth == -1) { //相当于一个剪枝
                return -1;
            }
        }
        if(node->right != NULL) {
            right_depth = getDepth(node->right, depth+1);
            if(right_depth == -1) { //相当于一个剪枝
                return -1;
            }
        }
        if(abs(left_depth-right_depth)<=1) {
            return max(left_depth, right_depth);
        }
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        bool is_balance = false;
        int depth = getDepth(root, 0);
        return depth != -1;
    }
};
