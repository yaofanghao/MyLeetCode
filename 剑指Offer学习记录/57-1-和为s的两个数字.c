/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 左右两端双指针法
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int left=0, right = numsSize-1;
    
    int* res = (int*)malloc(sizeof(int)*2);
    * returnSize = 2;

    while(left<right)
    {
        if(nums[left]+nums[right] == target)
        {
            res[0] = nums[left];
            res[1] = nums[right];
            return res;
        }
        else if (nums[left]+nums[right] < target) left++;
        else right--;
    }
    return NULL;
}