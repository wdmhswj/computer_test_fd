#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// 算法处理逻辑
void processInput(std::vector<int>& nums) {
    int left=0, right=nums.size()-1;
    while(left<right) {
        while(nums[left]%2==1) {    // 直到left遇到偶数
            ++left;
        }
        while(nums[right]%2==0){    // 直到right遇到奇数
            --right;
        }
        if(left<right){
            int tmp=nums[right];
            nums[right]=nums[left];
            nums[left]=tmp;
            ++left;
            --right;
        }
        // std::cout<<"test2";
    }
    for (int num : nums) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    // 读取输入文本
    std::ifstream infile("test1.txt");
    // 确认是否成功打开文件
    if (!infile.is_open()) {
        std::cerr<<"无法打开文件"<<std::endl;
        return 1;
    }

    // 存储读取的每一行
    std::string line;
    // 循环读取输入
    while (std::getline(infile, line)) {
        // 如果为空，直接跳过
        if (line.empty()) {
            continue;
        }
        // 将string转化为stringstream，便于转换为int
        std::stringstream ss(line);
        std::vector<int> nums;
        int num;
        while(ss>>num) {
            // std::cout<<"test1";
            nums.push_back(num);
        }
        processInput(nums);
    }
    // 关闭文件
    infile.close();
    return 0;

}
