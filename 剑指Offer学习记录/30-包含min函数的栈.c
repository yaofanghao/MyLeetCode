/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 10:49:32
 * @LastEditTime: 2023-05-14 11:16:08
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/

#define Size 30000

typedef struct {
    int stack[Size];
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* p = (MinStack*)malloc(sizeof(MinStack));
    p->top = -1;
    return p;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top == Size-1)
        return;
    obj->stack[++obj->top] = x;
}

void minStackPop(MinStack* obj) {
    if(obj->top == -1)
        return;
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackMin(MinStack* obj) {
    if(obj->top == 0) return obj->stack[0];

    int min = obj->stack[0];
    for (int i = obj->top; i >= 0; --i)
    {
        min = min < obj->stack[i] ? min:obj->stack[i];
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/