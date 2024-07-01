#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

void processInput(const std::vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    std::vector<int> result(nums);
    std::reverse(result.begin(), result.end());
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void processInput1(const std::vector<double>& nums) {
    if (nums.empty()) {
        return;
    }
   
    for (double num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void processInput2(const std::vector<std::string>& strings) {
    if (strings.empty()) {
        return;
    }
   
    for (const std::string& str : strings) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

int main() {
    // std::cout<<"test3";
    std::ifstream infile("doubles.txt");
    // std::ifstream infile("test.txt");
    if(!infile.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }
    std::string line;   // 读取的每一行
    while(std::getline(infile, line)) {
        // 若为空，直接跳过
        if(line.empty()) {
            // std::cout<<"test1";
            std::cout<<std::endl;
            continue;
        }
        // 跳过注释
        if (line[0]=='#') {
            continue;
        }
        // 使用stringstream将读取的行转换为流，以便从中读取整数
        std::stringstream ss(line);
        // std::vector<int> nums;
        // int num;
        // while(ss>>num) {
        //     // std::cout<<num<<std::endl;
        //     nums.push_back(num);
        // }

        // // 转化为double
        // double db;
        // std::vector<double> doubles;
        // while(ss>>db) {
        //     doubles.push_back(db);
        // }
        // processInput1(doubles);

        // 转化为string
        std::string str;
        std::vector<std::string> strings;
        while(ss>>str) {
            strings.push_back(str);
        }
        processInput2(strings);

        }
    // std::cout<<"test2";
    infile.close();
    return 0;
}

