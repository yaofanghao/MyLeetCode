/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 15:07:58
 * @LastEditTime: 2023-05-16 15:33:28
 * @LastEditors: yao fanghao
 */
class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) 
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int lenIntervals = intervals.size();
        if(lenIntervals==1) return intervals;

        sort(intervals.begin(), intervals.end(), cmp);        
        vector<vector<int>> res;            
        for(auto &it:intervals)
        {
            // 贪心算法
            // 维护区间的右端点比当前区间的左端点小，表示找到了一个新区间，进行添加即可
            if(res.empty()||res.back()[1]<it[0])
            {
                res.push_back(it);
            }
            
            // 否则进行合并区间
            else
            {
                res.back()[1] = max(res.back()[1], it[1]);
            }
        }
        return res;
    }
};