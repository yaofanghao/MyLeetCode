/*
 * @Author: yao fanghao
 * @Date: 2023-08-17 16:14:14
 * @LastEditTime: 2023-08-17 16:36:57
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int,int> hash;
    vector<int> res;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(hash.find(val)!=hash.end()){
            return false;
        }

        res.push_back(val);
        hash[val] = res.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val)==hash.end()){
            return false;
        }

        // 该值位置用最后一个元素替换，然后删除最后一个元素
        int val_location = hash[val]; // 该值位置
        res[val_location] = res[res.size()-1];
        hash[res[val_location]] = val_location;
        res.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = res.size();
        int random_num = rand()%n;
        return res[random_num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

