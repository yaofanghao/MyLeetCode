/*
 * @Author: yao fanghao
 * @Date: 2023-08-16 17:50:29
 * @LastEditTime: 2023-08-17 10:42:01
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i];
    }
    cout<<endl;
}

class Solution {
public:
    // 方法1
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int> res(m+n);
    //     if(n==0){
    //         return;
    //     }

    //     int flag1=0, flag2=0, i=0;
    //     for(int i=0; i<res.size(); i++){
    //         if(nums1[flag1]<nums2[flag2] && flag1<m){
    //             res[i] = nums1[flag1];
    //             flag1++; 
    //             cout<<"case A"<<endl;
    //         }
    //         else{
    //             res[i] = nums2[flag2];
    //             flag2++; 
    //             cout<<"case B"<<endl;
    //         }

    //         cout<<"i="<<i<<" flag1="<<flag1<<" flag2="<<flag2<<endl;
    //         printVector(res);
    //     }

    //     for(int i=0; i<nums1.size(); i++){
    //         nums1[i] = res[i];
    //     }
    // }

    // 方法2
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }   
        
        int flag1=m-1, flag2=n-1, count=0;
        for(count=m+n-1;flag1>=0&&flag1>=0;count--){
            cout<<"start, count="<<count<<" flag1="<<flag1<<" flag2="<<flag2<<endl;

            if(nums1[flag1]>nums2[flag2]){
                nums1[count] = nums1[flag1--];                
            }
            else{
                nums1[count] = nums2[flag2--];                
            }

            cout<<"end, count="<<count<<" flag1="<<flag1<<" flag2="<<flag2<<endl;
            printVector(nums1);
        }

        while(flag2>=0){
            nums1[count--] = nums2[flag2--];
        }
    }
};

int main(){
    vector<int> nums1, nums2;
    int num;
    cout << "enter nums1:" << endl;
    while(cin >> num) {
        nums1.push_back(num);
        if(getchar() == '\n') {
            break;
        }
    }
    
    cout << "enter nums2:" << endl;
    while(cin >> num) {
        nums2.push_back(num);
        if(getchar() == '\n') {
            break;
        }
    }
    
    printVector(nums1);
    printVector(nums2);

    // vector<int> nums1 = {1,2,3,0,0,0};
    // vector<int> nums2 = {2,5,6};

    // vector<int> nums1 = {2,0};
    // vector<int> nums2 = {1};

    // printVector(nums1);

    class Solution s;
    int m = nums1.size();
    int n = nums2.size();
    s.merge(nums1, m, nums2, n);

    cout<<"final result:"<<endl;
    printVector(nums1);

    return 0;
}