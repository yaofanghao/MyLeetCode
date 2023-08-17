/*
 * @Author: yao fanghao
 * @Date: 2023-08-17 20:53:22
 * @LastEditTime: 2023-08-17 20:57:40
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) 
{
    int size_s = s.size();
    int size_t = t.size();
    int i = 0;
    for (int j = 0; j < size_t; ++j) 
    {
        if (s[i] == t[j])  ++i;
    }
    if (i != size_s)  return false;
    return true;
}

int main(){
    string s,t;
    cout<<"enter first string s:"<<endl;
    getline(cin, s);
    cout<<"enter first string t:"<<endl;
    getline(cin, t);

    cout<<isSubsequence(s,t)<<endl;
    return 0;
}