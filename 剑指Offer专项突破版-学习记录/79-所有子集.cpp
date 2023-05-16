/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 15:54:44
 * @LastEditTime: 2023-05-16 16:15:19
 * @LastEditors: yao fanghao
 */
// https://leetcode.cn/problems/TVdhkn/solutions/1411943/suo-you-zi-ji-by-leetcode-solution-my7d/
// 迭代

class Solution {
public:

    int count(int n) 
    {
        int count = 0;
        while(n)
        {
            ++count;
            n = (n-1)&n;
        }
        return count;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int setSum = 1<<len; // 集合个数为2的len次
        vector<vector<int>> res;
        res.reserve(setSum);

        for(int i=0; i<setSum; i++)
        {
            int size = count(i); // 该二进制数中1的个数
            vector<int> temp;
            temp.reserve(size);
            for(int j=0; j<len; j++)
            {
                // 如果第j为1，则写入子集temp
                if((i>>j)&1) temp.push_back(nums[j]); 
            }
            res.push_back(temp);
        }
        return res;
    }
};