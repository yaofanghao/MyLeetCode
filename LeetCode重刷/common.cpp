/*
 * @Author: yao fanghao
 * @Date: 2023-08-17 11:42:01
 * @LastEditTime: 2023-09-23 17:02:01
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> split(std::string line){
    vector<int> numbers;
    while (std::getline(cin, line)) {
        if (line.empty()) {
            break;
        }        
        stringstream ss(line);
        string numStr;
        while (std::getline(ss, numStr, ',')) {
            int num = std::stoi(numStr);
            numbers.push_back(num);
        }
    }
    
    return numbers;
}

void printVector(vector<int>& nums)
{
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;    
}

int main() {
    std::string line; 
    vector<int> res = split(line);    
    int towersLength = res[0];
    int radius = res[1];
    // printVector(res);
    
    int max=0;
    int max_index=0;
    for(int i=0; i<towersLength; i++){
        if(res[4+3*i]>=max){
            max_index = 4+3*i;
            max = res[4+3*i];
        }        
    }
    // cout<<"max_index"<<max_index<<endl;    
    cout<<res[max_index-2]<<","<<res[max_index-1]<<endl;
    return 0;
}