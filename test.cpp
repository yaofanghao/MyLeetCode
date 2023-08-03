/*
 * @Author: yao fanghao
 * @Date: 2023-08-03 10:01:08
 * @LastEditTime: 2023-08-03 17:19:06
 * @LastEditors: yao fanghao
 */
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& num){
    cout<<"vector: ";
    for(auto i:num){
        cout<<i<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(10,0);
        vector<int> ans;
        for(auto i:nums1){
            res[i]++;
        }

        for(auto j:nums2){            
            if(res[j]>0){
                ans.push_back(j);
                cout<<"res[j]= "<<res[j]<<endl;
                res[j] = 0;
            }
            cout<<"j="<<j<<" ";
            printVector(res);
        }

        return ans;
    }
};

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    
    vector<int> ans;

    Solution* st = new Solution();
    ans = st->intersection(nums1, nums2);
    printVector(ans);

    return 0;
}