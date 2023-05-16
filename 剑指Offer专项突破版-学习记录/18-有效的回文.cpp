/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 09:48:13
 * @LastEditTime: 2023-05-16 09:51:00
 * @LastEditors: yao fanghao
 */
// 2023.2.20 双指针解法
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};
