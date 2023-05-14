/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 11:37:07
 * @LastEditTime: 2023-05-14 11:37:22
 * @LastEditors: yao fanghao
 */
// https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        struct Node* nodeNew = malloc(sizeof(struct Node));
        nodeNew->val = node->val;
        nodeNew->next = node->next;
        node->next = nodeNew;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        struct Node* nodeNew = node->next;
        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
    }
    struct Node* headNew = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) {
        struct Node* nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
    }
    return headNew;
}
