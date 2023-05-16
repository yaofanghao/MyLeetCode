/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 20:06:00
 * @LastEditTime: 2023-05-15 20:25:46
 * @LastEditors: yao fanghao
 */

// 二分查找找到该数字的最左和最右位置
int binarySearch(int* nums, int numsSize, int target, bool lower) {
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (lower && nums[mid] >= target)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int search(int* nums, int numsSize, int target) {
    int leftIdx = binarySearch(nums, numsSize, target, true);
    int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
    int ret = 0;
    if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target) {
        ret = rightIdx - leftIdx + 1;
    }
    return ret;
}
