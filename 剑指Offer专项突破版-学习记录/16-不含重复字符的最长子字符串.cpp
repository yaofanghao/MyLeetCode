/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 09:39:57
 * @LastEditTime: 2023-05-16 09:43:21
 * @LastEditors: yao fanghao
 */
// 双指针
class Solution {
public:
   int lengthOfLongestSubstring(string s) {
       if(s.length() <= 1) return s.length();
       int i = 0, j = i + 1, n = s.length();
       unordered_map<char,int> cnt;
       cnt[s[i]] = 0;
       int maxL = 1;
       while(j < n){
           char tmp = s[j];
           if(cnt.find(tmp) != cnt.end()){
               i = max(i,cnt[tmp] + 1);
           }
           cnt[tmp] = j;
           maxL = max(maxL, j - i + 1);
           j ++;
       }
       return maxL;
   }
};