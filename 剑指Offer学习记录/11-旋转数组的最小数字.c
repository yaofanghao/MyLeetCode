
// https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/


int minArray(int* numbers, int numbersSize)
{
    int left = 0;
    int right = numbersSize - 1;
    if (numbers[left] < numbers[right]) {
        return numbers[left];
    }
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if (numbers[right] > numbers[mid]) 
        {
            right = mid;
        // 右边的小于中间的，说明左边的一定是有序的。
        } 
        else if (numbers[right] < numbers[mid]) 
        {
            left = mid + 1;
        }
        else 
        {
            right --;
        }
    }
    return numbers[left];
}