/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 11:43:36
 * @LastEditTime: 2023-05-14 11:54:35
 * @LastEditors: yao fanghao
 */

class Solution {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end());
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/solutions/838947/zi-fu-chuan-de-pai-lie-by-leetcode-solut-hhvs/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。