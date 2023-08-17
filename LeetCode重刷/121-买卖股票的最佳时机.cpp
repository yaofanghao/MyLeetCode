/*
 * @Author: yao fanghao
 * @Date: 2023-08-17 14:35:32
 * @LastEditTime: 2023-08-17 15:50:12
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int lowest=INT_MAX;
    int maxprofix=0;
    for(int i=0; i<prices.size(); i++){
        lowest = min(lowest, prices[i]);            
        maxprofix = max(maxprofix, prices[       \
        i]-lowest);

        // cout<<"lowest="<<lowest<<" maxprofix="<<maxprofix<<endl;
    }
    return maxprofix;
}

int main(){
    vector<int> num = {7,6,4,3,1};
    int result = maxProfit(num);
    std::cout << result << endl;

    return 0;
}