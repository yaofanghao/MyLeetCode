/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 22:04:18
 * @LastEditTime: 2023-05-14 22:06:26
 * @LastEditors: yao fanghao
 */

// 用C语言实现哈希表
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

char firstUniqChar(char* s) {
    struct hashTable* frequency = NULL;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int ikey = s[i];
        struct hashTable* tmp;
        HASH_FIND_INT(frequency, &ikey, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = ikey;
            tmp->val = 1;
            HASH_ADD_INT(frequency, key, tmp);
        } else {
            tmp->val++;
        }
    }
    for (int i = 0; i < n; i++) {
        int ikey = s[i];
        struct hashTable* tmp;
        HASH_FIND_INT(frequency, &ikey, tmp);
        if (tmp != NULL && tmp->val == 1) {
            return s[i];
        }
    }
    return ' ';
}

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/solutions/664350/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-by-3zqv5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。