/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 22:26:48
 * @LastEditTime: 2023-05-12 22:42:45
 * @LastEditors: yao fanghao
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* exchange(int* nums, int numsSize, int* returnSize){
    int left = 0;
    int right = numsSize-1;

    while(left<right)
    {
        while(left<right && (nums[left]%2==1)) left++;
        while(left<right && (nums[right]%2==0)) right--;

        // 左偶右奇 交换
        if(left<right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;            
        }
    }
    *returnSize = numsSize;
    return nums;
}