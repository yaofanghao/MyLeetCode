/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 22:10:40
 * @LastEditTime: 2023-05-12 22:24:45
 * @LastEditors: yao fanghao
 */

// 方法1 简单
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> numbers;
        int max_num = 0;
        while (n) {
            max_num = max_num * 10 + 9;
            n--;
        }
         
        for (int i = 1; i <= max_num; i++) {
            numbers.push_back(i);
        }
        return numbers;
    }
};

// 方法2：回溯dfs 复杂
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 9; j++)
                dfs(1, i, to_string(j)); //dfs从1开始，因为第0位已经确定了
        return res;
    }
    void dfs(int k, int n, string s)
    {
        if(k==n)
        {
            res.emplace_back(stoi(s));
            return;
        }
        for(int i = 0; i < 10; i++)
            dfs(k+1, n, s+to_string(i));
    }
};





