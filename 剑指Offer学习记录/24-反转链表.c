/*
 * @Author: yao fanghao
 * @Date: 2023-05-13 20:34:41
 * @LastEditTime: 2023-05-13 20:46:13
 * @LastEditors: yao fanghao
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while(cur)
    {   
        struct ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}