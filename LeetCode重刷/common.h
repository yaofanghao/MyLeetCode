#ifndef COMMON_H
#define COMMON_H

#include <vector>

void input_array();

void input_matrix();

void input_string();

void input_strings();

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* _next):val(_val),next(_next){}
};

void input_list_node();

void printVector(vector<int>& nums);

#endif