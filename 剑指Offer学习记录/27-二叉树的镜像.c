/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 10:33:24
 * @LastEditTime: 2023-05-14 10:43:06
 * @LastEditors: yao fanghao
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root==NULL) return NULL;

    struct TreeNode* t = mirrorTree(root->left);
    root->left = mirrorTree(root->right);
    root->right = t;
    return root;
}