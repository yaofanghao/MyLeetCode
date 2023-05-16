/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 21:48:31
 * @LastEditTime: 2023-05-15 21:56:59
 * @LastEditors: yao fanghao
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers;
        int size = nums.size();
        for (int i = 0; i <= size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int j = i + 1;
            int k = size - 1;
            
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    ++j;
                }else if (nums[j] + nums[k] > target) {
                    --k;
                }else {
                    if (nums[j] != nums[j - 1] || j - 1 == i) {
                        answers.push_back({nums[i], nums[j], nums[k]});
                    }
                    ++j;
                }
            }
        }
        return answers;
    }
};