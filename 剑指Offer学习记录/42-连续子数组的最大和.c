/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 21:22:28
 * @LastEditTime: 2023-05-14 21:23:42
 * @LastEditors: yao fanghao
 */

// 动态规划
int maxSubArray(int* nums, int numsSize) {
    int pre = 0, maxAns = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]);
        maxAns = fmax(maxAns, pre);
    }
    return maxAns;
}
