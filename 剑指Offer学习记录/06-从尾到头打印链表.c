/*
 * @Author: yao fanghao
 * @Date: 2023-05-11 21:49:16
 * @LastEditTime: 2023-05-11 22:10:01
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/


#include <stdio.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// void printListNode(struct ListNode* head)
// {
//     if(head)
//     {
//         print("%d", head->val);
//         head = head->next;
//     }
//     return 0;
// }

// struct ListNode* reverseListNode(struct ListNode* head, int* returnSize){
//     if(head==NULL) return NULL;
//     struct ListNode* dummy = malloc(sizeof(struct ListNode));
//     dummy->next = head;
//     struct ListNode* pre = dummy;
//     struct ListNode* cur = head;
//     while(cur)
//     {
//         struct ListNode* temp = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = temp;
//     }  
//     return pre;
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode*p = head;
    int cnt = 0;
    while(p){                       //遍历链表得到链表结点数量
        ++cnt;
        p = p->next;
    }       

    * returnSize = cnt;
    int* ans = (int*)malloc(cnt*sizeof(int));
    int i = cnt-1;
    p = head;
    while(p){
        ans[i--] = p->val;           //倒序将链表元素放入数组
        p = p->next;
    }
    return ans;
}

int main()
{
    
    return 0;
}