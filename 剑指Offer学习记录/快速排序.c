/*
 * @Author: yao fanghao
 * @Date: 2023-05-12 20:49:37
 * @LastEditTime: 2023-05-12 21:03:59
 * @LastEditors: yao fanghao
 */
#include <stdio.h>
#include <stdlib.h>
 
#define  N  10

void printArr(int *a)
{
    for(int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
    printf("\n");
}

//快速排序法
int quick_sort(int *a, int low, int high)
{
	int i = low;	//第一位
	int j = high;	//最后一位
	int key = a[i];  //将第一个数作为基准值-- 先找到一个基准值
 
	//进行排序---> 最终结果就是 左面的 都比基准值小 ，右面的都比 基准值大，所以这是所有循环的结束条件
	while (i < j)
	{
		//下面的循环执行的条件是 如果右面的比基准值大，就赋一下值，否则继续向前移动
                //---如果直接把循环写成下面这样---
		//while(a[j] >= key) //如果下面的不写这个i<j,这个就出错、越界，并且排序不准--理由：
		//如果i<j,并且： 右面的值 大于 基准值 时，j往前移动一个
					//i 跟 j 的可能情况 只有 i<j i==j
		printf("i=%d,j=%d\n",i,j);
        while(i < j && a[j] >= key)//i<j 是 当前while循环的结束条件，如果没有这个，i会大于j，出现越界，错误 
		{
			j--;//继续走
		}
        printArr(a);

        //如果不成立，也就是 a[j] <= key;右面的比key小了，那就换个位置		
        //把a[j]的数据给a[i]	
		a[i] = a[j];	
        printArr(a);
 
		//将事先保存好的基准值与左边的值进行比较，如果基准值大，保持不变，i往前
		//然后 判断一下这个新的a[i]，也就是之前的a[j]跟key值的关系---> 一定是 a[i]<key
		//所以把i向前移动一下，i++
        printf("i=%d,j=%d\n",i,j);
		while(i < j && a[i] <= key)
		{
			i++;
		}
		//移动完以后，把新的位置的a[i]的数值 给刚才的 a[j],然后开始下一次循环
		a[j] = a[i];
        printf("i=%d,j=%d\n",i,j);
        printArr(a);
        printf("end\n");
	}
 
	//跳出循环，将基准值放入数据a[i]中
	a[i] = key;
	//对基准值左边 的所有数据 再次进行快速查找（递归）
	if (i-1 > low) 
	{
		quick_sort(a, low, i-1);
	}
 
	//对基准值右边的所有数据再次进行快速查找（递归）
	if (i+1 < high)
	{
		quick_sort(a, i+1, high);
	}
 
	return 0;
} 
 
int main(int argc, const char *argv[])
{
	int a[N] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};//先整了个数组，初始化了一堆数	
 
	int i = 0;
	printf("before quicksort:\n");
    printArr(a);
	putchar(10);
    
    printf("start quicksort:\n");
	//调用-快排
	quick_sort(a, 0, N-1);//数组，0 ，9
														
	printf("after quicksort:\n");
    printArr(a);
	putchar(10);
	
	return 0;
}