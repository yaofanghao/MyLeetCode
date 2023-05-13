/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 21:46:38
 * @LastEditTime: 2023-05-12 22:04:43
 * @LastEditors: yao fanghao
 */

double myPow(double x, int n){
    if(n==0) return 1;
    if(n==1) return x;
    if(n==-1) return 1/x;

    double res = myPow(x, n>>1);  // n>>1表示向下取整的折半
    res *= res;
    if(n&1)  // 求余数判断奇偶
    {
        res *= x;
    }
    return res;
}