/*
 * @Author: yao fanghao
 * @Date: 2023-05-16 11:34:08
 * @LastEditTime: 2023-05-16 11:35:51
 * @LastEditors: yao fanghao
 */
// 2023.4.1 栈
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> res;
        // res.push(asteroids[0]);
        int n=asteroids.size();
        for(int i=0; i<n-1; i++)
        {
            // 左正右负 相对碰撞
            if((asteroids[i]>0)&&(asteroids[i+1]<0))
            {
                res.push(max(asteroids[i],asteroids[i+1]));
            }
            // 其他情况都不碰撞
            else res.push(asteroids[i]);
        }
        return res;

    }
};