/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 22:00:21
 * @LastEditTime: 2023-05-15 22:13:23
 * @LastEditors: yao fanghao
 */
// 维护两个指针
// 当指针P1和P2之间的子数组数字之和小于k时，向右移动指针P2，直到两个指针之间的子数组数字之和大于k，
// 否则向右移动指针P1，直到两个指针之间的子数组数字之和小于k。
int minSubArrayLen(int target, int* nums, int numsSize){
    int left=0;
    int sum=0;
    int length=INT_MAX;
    for(int right=0; right<numsSize; right++)
    {
        sum += nums[right];
        while(left<=right && sum >= target)
        {
            length = fmin(length, right-left+1);
            sum -= nums[left];
            left++;
        }
    }
    return length == INT_MAX ? 0:length;
}