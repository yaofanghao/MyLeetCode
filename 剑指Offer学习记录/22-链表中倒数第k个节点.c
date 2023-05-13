/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 22:44:08
 * @LastEditTime: 2023-05-12 22:44:44
 * @LastEditors: yao fanghao
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* n2 = head;
    struct ListNode* n1 = head;
    int i=0;
    for(i = 0; i < k; i++)
    {
        if(n2->next!=NULL)
        {
            n2 = n2->next;
        }
        else
        {
            return n1;
            break;
        }
    }
    while(n2 != NULL)
    {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}
