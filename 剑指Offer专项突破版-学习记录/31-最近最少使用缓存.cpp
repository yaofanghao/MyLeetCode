// https://leetcode.cn/problems/OrIXps/solutions/1398888/zui-jin-zui-shao-shi-yong-huan-cun-by-le-p3c2/

// 哈希表+双向链表

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache; // 重点关注这个哈希表！
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    // 以正整数作为容量 capacity 初始化 LRU 缓存
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1
    int get(int key) {
        if (!cache.count(key)) 
        {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    // 如果关键字已经存在，变更其数据值；
    // 如果关键字不存在，插入该组「关键字-值」；
    // 当缓存容量达到上限时，删除最久未使用的数据值，写入新数据
    void put(int key, int value) {
        if (!cache.count(key)) 
        {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) 
            {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else 
        {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
方法二
C++STL 方法实现
class LRUCache {
    int cache_capacity;
    list<pair<int,int>> mylist;
    unordered_map<int,list<pair<int,int>>::iterator> key2addr;
public:
    LRUCache(int capacity):cache_capacity(capacity) {
    }
    
    int get(int key) {
        if(key2addr.count(key)==0)return -1;
        list<pair<int,int>>::iterator it=key2addr[key];
        int value=it->second;
        mylist.erase(it);
        //头插
        key2addr[key]=mylist.insert(mylist.begin(),{key,value});
        return value;
    }
    
    void put(int key, int value) {
        if(key2addr.count(key))
            mylist.erase(key2addr[key]);
        else if(key2addr.size()>=cache_capacity){
            key2addr.erase(mylist.back().first);
            mylist.pop_back();
        }
        //头插
        key2addr[key]=mylist.insert(mylist.begin(),{key,value});
    }
}; 
*/