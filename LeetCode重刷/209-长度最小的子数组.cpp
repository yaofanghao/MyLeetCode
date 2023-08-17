#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int start=0, end=0, sum=0;
    int min_length = INT_MAX;
    while(end<nums.size()){
        sum += nums[end];
        while(sum>=target){
            min_length = min(min_length, end-start+1);
            sum -= nums[start];
            ++start;
        }
        end++;
    }    

    return min_length==INT_MAX? 0: min_length;
}

int main(){

    int target;
    cout<<"Enter target:"<<endl;
    cin>>target;
    
    vector<int> nums;
    int num;
    cout<<"Enter nums:"<<endl;
    while(cin>>num){
        nums.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }

    cout<<"min length is: "<<minSubArrayLen(target,nums)<<endl;
    return 0;
}