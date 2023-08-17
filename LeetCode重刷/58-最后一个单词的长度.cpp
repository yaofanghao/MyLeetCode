/*
 * @Author: yao fanghao
 * @Date: 2023-08-17 16:52:41
 * @LastEditTime: 2023-08-17 17:09:54
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int sum=0,flag=0;
    for(int j=s.size()-1; j>=0; j--){
        if(s[j]==' ' && flag==0){
            continue;
        }
        else if(s[j]==' ' && flag==1){
            break;
        }
        else{
            sum++;
            flag=1;
        }
    }
    return sum;
}

int main(){
    cout << "Enter strings:" << endl;  

    string s;
    getline(cin, s);

    cout<<"Length of last word is:"<<endl;
    cout<<lengthOfLastWord(s)<<endl;

    return 0;
}