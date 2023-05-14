/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 11:16:02
 * @LastEditTime: 2023-05-14 11:19:46
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int *stack = (int *)malloc(sizeof(int) * pushedSize);
    int top = 0;
    for (int i = 0, j = 0; i < pushedSize; i++) {
        stack[top++] = pushed[i];
        while (top > 0 && stack[top - 1] == popped[j]) {
            top--;
            j++;
        }
    }
    free(stack);
    return top == 0;
}