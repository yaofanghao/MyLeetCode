/*
 * @Author: yao fanghao
 * @Date: 2023-08-20 14:31:52
 * @LastEditTime: 2023-08-20 14:36:25
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<double>& nums)
{
    for(vector<double>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;    
}

int main() {
    vector<double> nums;
    double num;
    while(cin >> num) {
        nums.push_back(num);
        if(getchar() == '\n') {
            break;
        }
    }


    printVector(nums);

    if(nums.size()<=1){
        return 1;
    }

    int maxLen=1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]-nums[i-1]>0){
            maxLen++;
            cout<<"nums i="<<nums[i]<<endl;
            cout<<maxLen<<endl;
        }
        else{
            maxLen = 1;
        }

    }

    cout<<maxLen<<endl;

    return maxLen;

}
// 64 位输出请用 printf("%lld")