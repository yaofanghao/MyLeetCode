/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 17:35:38
 * @LastEditTime: 2023-05-16 20:17:33
 * @LastEditors: yao fanghao
 */

#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;
#define _MIN(A,B) A>B?B:A

int sig(char s, int n)
{
    char s2 = n+'0';
    if(s==s2) return 1;
    else return 0;
}

void printDP(vector<vector<int>> dp, int len)
{
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
        }
        printf("\n");
    }
}

int minFlipsMonoIncr(string s) {
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(2,0));
    dp[0][0] = sig(s[0], 1);  // 第一个如果是1，dp1需要反转
    dp[0][1] = sig(s[0], 0);  // 第一个如果是0，dp2需要反转
    for(int i=1; i<len; ++i)
    {
        cout<<"i为"<<i<<endl;
        cout<<s[i]<<endl;
        cout<<sig(s[i],1)<<endl;
        cout<<sig(s[i],0)<<endl;
        cout<<endl;

        dp[i][0] = dp[i-1][0]+sig(s[i],1);
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + sig(s[i], 0);
    }

    printDP(dp, len);

    return _MIN(dp[len-1][0], dp[len-1][1]);
}


int main()
{
    // char s = '1';
    // cout<<sig(s, 1)<<endl;
    // cout<<sig(s, 0)<<endl;
    string s = "00110";
    cout<<minFlipsMonoIncr(s)<<endl;

    return 0;
}