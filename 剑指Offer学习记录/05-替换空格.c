/*
 * @Author: yao fanghao
 * @Date: 2023-05-11 21:19:40
 * @LastEditTime: 2023-05-11 21:49:50
 * @LastEditors: yao fanghao
 */

// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceSpace(char* s){
    char *returned=calloc(strlen(s)*3+1,sizeof(char));
    int i=0,k=0;
    while(s[i]!='\0'){
        if(s[i]==' '){
            returned[k++]='%';
            returned[k++]='2';
            returned[k++]='0';
            i++;
        }
        else{
            returned[k++]=s[i];
            i++;
        }
    }
    return returned;
}

int main()
{    
    char* s = "We are happy";
    char* res = replaceSpace(s);

    for(int i=0; i<strlen(res); i++)
    {
        printf("%c", res[i]);
    }    

    return 0;
}