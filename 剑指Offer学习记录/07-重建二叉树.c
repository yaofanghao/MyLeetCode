/*
 * @Author: yao fanghao
 * @Date: 2023-05-11 22:13:48
 * @LastEditTime: 2023-05-12 20:40:03
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/

#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(!preorderSize) return NULL;

    // 1、通过【前序遍历列表】确定【根节点 (root)】
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    // 2、将【中序遍历列表】的节点分割成【左分支节点】和【右分支节点】
    int i=0;
    for( ; i<inorderSize; i++)
    {
        if(inorder[i] == preorder[0]) break;
    } 
    
    // 3、递归寻找【左分支节点】中的【根节点 (left child)】和 【右分支节点】中的【根节点 (right child)】
    if(i) root->left = buildTree(preorder+1, i, inorder, i);
    if(inorderSize-i-1)  root->right = buildTree(preorder+i+1,inorderSize-i-1 , inorder+1+i ,inorderSize-i-1);
    return root;   
}

int main()
{
    
    return 0;
}