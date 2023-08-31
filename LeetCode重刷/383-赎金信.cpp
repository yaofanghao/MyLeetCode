/*
 * @Author: yao fanghao
 * @Date: 2023-08-18 16:23:43
 * @LastEditTime: 2023-08-18 16:34:56
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(vector<int>& nums)
{
    cout<<"print vector..."<<endl;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;    
}

bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
        
    vector<int> res(26);
    for(auto i:magazine){
        res[i-'a']++;
    }    

    printVector(res);
    
    for(auto j:ransomNote){
        res[j-'a']--;
        printVector(res);
        if(res[j-'a']<0){
            return false;
        }
    }

    printVector(res);

    return true;
}

int main(){
    string r,m;

    cout<<"Enter ransomNote:"<<endl;
    getline(cin, r);

    cout<<"Enter magazine:"<<endl;
    getline(cin, m);

    cout<<"Result is"<<endl;
    bool output = canConstruct(r, m);
    cout<<output<<endl;
    return 0;
}
