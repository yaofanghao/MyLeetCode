/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 21:37:16
 * @LastEditTime: 2023-05-12 21:42:40
 * @LastEditors: yao fanghao
 */

// 方法1
int hammingWeight(uint32_t n) {
    int sum = 0;
    while(n)
    {
        if(n&1) sum++;
        n=n>>1;
    }
    return sum;
}

// 方法2
int hammingWeight(uint32_t n) {
    int sum = 0;
    while(n)
    {
        ++sum;
        n = (n-1)&n;
    }
    return sum;
}