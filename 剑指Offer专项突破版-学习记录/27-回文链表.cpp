/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 10:01:48
 * @LastEditTime: 2023-05-16 10:02:08
 * @LastEditors: yao fanghao
 */
// 2023.2.23  比较简单的题目
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {

//         // 链表复制到数组中
//         vector<int> arr;
//         while(head!=nullptr)
//         {
//             int arr_val = head->val;  
//             cout<<arr_val<<endl;        
//             arr.emplace_back(arr_val);
//             head = head->next;
//         }        

//         //在数组中用双指针法判断是否回文
//         int left=0, right=arr.size()-1;
//         while(left<right)
//         {
//             if(arr[left]==arr[right])
//             {
//                 left++;
//                 right--;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// 2023.2.27 方法二 反转链表后逐个比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        } // 得到翻转后的链表pre

        while(head!=nullptr &&  pre!=nullptr)
        {
            if(head->val != pre->val) return false;
            cout << "head:" << head->val <<endl;
            cout << "pre:" << pre->val <<endl;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};

