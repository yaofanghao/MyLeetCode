/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 22:43:07
 * @LastEditTime: 2023-05-15 22:47:37
 * @LastEditors: yao fanghao
 */

// 把0都置为-1，然后等同于10-和为k的子数组.cpp
// 转换为求和为0的子数组

class Solution {
public:
    // 1. 将0替换为-1，遍历求前缀和
    // 2. 在遍历过程中，把前缀和和下标进行映射（多个相同前缀和时只记录最小的下标）
    // 3. 每遍历一个元素，就用「当前前缀和」去前面已经统计的前缀和中找到一个使得两者之间区间为0的，并计算这个区间长度
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] ? 1 : -1);
            if (m.count(sum)) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};