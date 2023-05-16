
// https://leetcode.cn/problems/QTMn0o/solutions/1399223/he-wei-k-de-zi-shu-zu-by-leetcode-soluti-1169/

// 因为有负数，所以不能用滑动窗口
// 前缀和+哈希表方法实现
// 从头到尾逐个扫描 求出前i个数字之和，并且将和保存下来。数组的前i个数字之和记为x
// 如果存在一个j（j＜i），数组的前j个数字之和为x-k，那么数组中从第i+1个数字开始到第j个数字结束的子数组之和为k
// 这个题目需要计算和为k的子数组的个数
// 当扫描到数组的第i个数字并求得前i个数字之和是x时，
// 需要知道在i之前存在多少个j并且前j个数字之和等于x-k。
// 所以，对每个i，不但要保存前i个数字之和，还要保存每个和出现的次数
// 分析到这里就会知道我们需要一个哈希表，哈希表的键是前i个数字之和，值为每个和出现的次数
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(auto &i:nums)
        {
            pre += i;            
            count += mp[pre-k];
            mp[pre]++;
        }
        return count;
    }
};