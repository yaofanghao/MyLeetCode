/*
 * @Author: yao fanghao
 * @Date: 2023-05-11 17:46:44
 * @LastEditTime: 2023-05-11 21:16:09
 * @LastEditors: yao fanghao
 */
 
#include <stdio.h>
#include <stdbool.h>

// https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
/*
 * 输入 **matrix 是长度为 matrixSize 的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *matrixColSize 数组作为另一输入，*matrixColSize 数组的长度也为 matrixSize
 */
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrix == NULL|| matrixSize == 0 || *matrixColSize == 0)  return false;

    int i=0, j=*matrixColSize-1;
    while(i<matrixSize && j>=0)
    {
        if(matrix[i][j]==target)  return true;
        else if(matrix[i][j]>target)  j--;
        else i++;
    }
    return false;
}

int main()
{
    // int matrix[5][5] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    // int matrix[5][4] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
    // int matrixSize = sizeof(matrix[0])/sizeof(matrix[0][0]);
    // int matrixColSize = sizeof(matrix)/sizeof(matrix[0]);
    
    // printf("matrixSize=%d\n",matrixSize);
    // printf("matrixColSize=%d\n", matrixColSize);

    // int target = 5;

    // bool res = findNumberIn2DArray(**matrix, matrixSize, *matrixColSize, target);
    // printf(res);

    return 0;
}
