/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 20:41:22
 * @LastEditTime: 2023-05-15 21:04:44
 * @LastEditors: yao fanghao
 */

// 滑动窗口法
class Solution {
public:

    int betweenSum(int left, int right){
        int sum = 0;
        for(int i=left; i<=right; i++)
        {
            sum += i;
        }
        return sum;
    }

    vector<int> betweenVector(int left, int right){
        vector<int> res;
        for(int i=left; i<=right; i++)
        {
            res.push_back(i);
        }
        return res;
    }

    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;     
        if(target<3) return res;

        int left=1, right=2;

        while(left<right)
        {
            if(betweenSum(left,right) == target)
            {
                res.push_back(betweenVector(left, right)); 
                left++;  
            } 
            else if(betweenSum(left,right) < target) right++;
            else left++;
        }
        return res;

    }
};