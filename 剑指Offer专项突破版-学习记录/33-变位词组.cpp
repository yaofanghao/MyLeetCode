/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 11:22:24
 * @LastEditTime: 2023-05-16 11:31:42
 * @LastEditors: yao fanghao
 */

// 26个字母映射到26个质数 通过乘积判断是否相同

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long,vector<string>> hm;
        const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        const long long mod = 1e9 + 7;
        for(auto str:strs)
        {
            long long key = 1;
            for(auto c:str){
                key *= prime[c-'a'];
                key %= mod;
            }
            hm[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto &it:hm) 
        {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};