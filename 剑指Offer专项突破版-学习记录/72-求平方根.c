
// 二分查找

int mySqrt(int x){
    if(x==0) return 0;
    if(x>=1 && x<4) return 1;

    int left=1,right=x/2;
    while(left <= right)
    {
        long mid = (left+right)>>1; // 防止下列乘法溢出，用long
        if(mid*mid<=x && (mid+1)*(mid+1)>x) 
            return (int)mid; // long转为ing
        else if(mid*mid>x) 
            right=mid-1;
        else 
            left = mid+1;
    }
    return -1;
}