/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 16:50:47
 * @LastEditTime: 2023-05-16 17:34:28
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/JEj789/description/

#include <iostream>
#include <vector>
#define _min(A,B,C) A>B?(B>C?C:B):(A>C?C:A)
using namespace std;

// 相邻房子颜色不能相同
// 状态转移方程:
//      dp[i][j]=min(dp[i−1][(j+1)mod3],dp[i−1][(j+2)mod3])+costs[i][j]

void printDP(vector<vector<int>>& dp, int len)
{
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
        }
        printf("\n");
    }
}

int minCost(vector<vector<int>>& costs) {
    
    int len = costs.size();
    vector<vector<int>> dp(len, vector<int>(3,0));
    // printDP(dp, len);

    for(int j=0; j<3; ++j)
    {
        dp[0][j] = costs[0][j];            
    }

    for(int i=1; i<len; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]) + costs[i][j];
        }
    }
    printDP(dp, len);

    return _min(dp[len-1][0], dp[len-1][1], dp[len-1][2]);
}

int main()
{
    vector<vector<int>> costs;
    costs.push_back({17,2,17});
    costs.push_back({16,16,5});
    costs.push_back({14,3,19});

    printDP(costs, 3);

    int costs_min;
    costs_min = minCost(costs);
    cout<<costs_min<<endl;
    return 0;
}