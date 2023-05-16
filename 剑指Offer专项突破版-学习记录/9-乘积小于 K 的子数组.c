/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 22:13:52
 * @LastEditTime: 2023-05-15 22:22:55
 * @LastEditors: yao fanghao
 */
// 维护两个指针
int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    
    int left=0;
    long sum=1;
    int count=0;
    for(int right=0; right<numsSize; right++)
    {
        sum *= nums[right];
        while(left<=right && sum>=k)
        {
            sum /= nums[left++];
        }
        count += right-left+1; // 这句是关键
    }
    return count;
}