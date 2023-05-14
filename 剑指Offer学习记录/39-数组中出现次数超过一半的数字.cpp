/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 11:57:32
 * @LastEditTime: 2023-05-14 11:57:53
 * @LastEditors: yao fanghao
 */
// 2023.3.24 摩尔投票法
// 2023.4.14 二刷
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(int i:nums)
        {
            if(i==candidate)
            {
                count++;
            }
            else if(--count<0)
            {
                candidate = i;
                count = 1;
            }
        }
        return candidate;
    }
};
