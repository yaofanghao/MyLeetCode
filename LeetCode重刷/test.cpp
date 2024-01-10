/*
 * @Author: yao fanghao
 * @Date: 2023-08-20 14:31:52
 * @LastEditTime: 2023-09-23 16:44:54
 * @LastEditors: yao fanghao
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> numbers;
    std::string line;
    
    // 读取多行输入直到遇到空行
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        
        // 使用 stringstream 和 getline 将每行的数字以逗号为分隔符拆分
        std::stringstream ss(line);
        std::string numStr;
        while (std::getline(ss, numStr, ',')) {
            int num = std::stoi(numStr);
            numbers.push_back(num);
        }
    }
    
    // 输出数字
    for (int num : numbers) {
        std::cout << num << " ";
    }
    
    return 0;
}
