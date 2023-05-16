/*
 * @Author: yao fanghao
 * @Date: 2023-05-15 21:25:33
 * @LastEditTime: 2023-05-15 21:26:28
 * @LastEditors: yao fanghao
 */
char* reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
    return s;
}
char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    //反转前 n 个字符
    s = reverse(s, 0, n - 1);
    //反转 k 到末尾的字符
    s = reverse(s, n, len - 1);
    //反转整个字符串
    s = reverse(s, 0, len - 1);
    return s;
}
