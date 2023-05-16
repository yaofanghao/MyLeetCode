/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 15:45:36
 * @LastEditTime: 2023-05-16 15:52:22
 * @LastEditors: yao fanghao
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 归并排序
struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

struct ListNode* toSortList(struct ListNode* head, struct ListNode* tail) {
    if (head == NULL) {
        return head;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    struct ListNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head, NULL);
}

// struct ListNode* sortList(struct ListNode* head){
    // 插入排序 runtime error
    // if(head==NULL) return NULL;
    // struct ListNode* dummy = malloc(sizeof(struct ListNode));
    // dummy->next = head;
    // struct ListNode* lastSorted = head;
    // struct ListNode* curr = head->next;
    // while(curr!=NULL)
    // {
    //     if(lastSorted->val <= curr->val)
    //     {
    //         lastSorted = lastSorted->next;
    //     }
    //     else
    //     {
    //         struct ListNode* pre = dummy;
    //         if(pre->next->val <= curr->val)
    //         {
    //             pre = pre->val;
    //         }
    //         lastSorted->next = curr->next;
    //         curr->next = pre->next;
    //         pre->next = curr;
    //     }
    //     curr =  lastSorted->next;
    // }
    // return dummy->next;
// }