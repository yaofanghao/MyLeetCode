/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 21:29:52
 * @LastEditTime: 2023-05-14 21:45:32
 * @LastEditors: yao fanghao
 */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 转换为 字符串数组
        vector<string> vs;
        for (auto& num : nums) vs.emplace_back(to_string(num));
        
        // 自定义排序
        sort(vs.begin(), vs.end(), [&](const string& s1, const string& s2) {
            return s1 + s2 < s2 + s1;
        });

        // 组合
        string ans = "";
        for (auto& s : vs) ans += s;
        return ans;
    }
};
