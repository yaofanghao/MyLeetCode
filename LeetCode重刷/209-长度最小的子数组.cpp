#include <iostream>
#include <vector>
using namespace std;

void print_between(int start, int end, vector<int>& nums){
    for(int i=start; i<end+1; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int start=0, end=0, sum=0;
    int min_length = INT_MAX;
    while(end<nums.size()){
        sum += nums[end];
        while(sum>=target){
            min_length = min(min_length, end-start+1);
            sum -= nums[start];
            ++start;

            print_between(start, end, nums);
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
    int res = minSubArrayLen(target,nums);
    cout<<"min length is: "<<res<<endl;
    return 0;
}