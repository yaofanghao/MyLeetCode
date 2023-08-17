// 2023.3.1 摩尔投票法 十分巧妙
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int cnt = 1;
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i]==num) 
            {
                cnt++;   
            }            
            else
            {
                cnt--;
                if(cnt == 0)
                {
                    num = nums[i]; 
                    cnt = 1;                   
                }
            }
        }
        return num;
    }
};