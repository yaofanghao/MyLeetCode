/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 11:21:18
 * @LastEditTime: 2023-05-14 11:36:33
 * @LastEditors: yao fanghao
 */
// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<int> levelOrder(TreeNode* root) 
    {
        vector<int>vec;
        queue<TreeNode*>line;
        TreeNode* p = root;
        //初始放入根节点
        line.push(root);
        while (!line.empty())
        {
            //elem为队首元素
            TreeNode* elem = line.front();
            vec.push_back(elem->val);
            line.pop();
            if (elem->left) 
            {
                line.push(elem->left);
            }
            //line.push(elem->left);
            if (elem->right) 
            {
                line.push(elem->right);
            }
        }
        return vec;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(9);
    TreeNode* t3 = new TreeNode(20);
    TreeNode* t4 = new TreeNode(15);
    TreeNode* t5 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;
    Solution* st = new Solution();
    vector<int>nums = st->levelOrder(t1);
    for (auto elem : nums) {
        cout << elem << "\t";
    }
    cout << endl;
}