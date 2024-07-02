#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int num;
    std::vector<int> nums;
    while(std::cin>>num) {
        nums.push_back(num);
    }
    int n=nums.size();
    if (n==0) {
        std::cout<<0;
        return 0;
    }
    std::vector<int> digit_last(10,-1);
    std::vector<int> last(n, -1);

    for(int i=0; i<n; ++i) {
        last[i]=digit_last[nums[i]];
        digit_last[nums[i]]=i;
    }

    std::vector<int> dp(n);
    dp[0]=0;
    for(int i=1; i<n; ++i) {
        dp[i] = dp[i-1]+1;
        if (last[i] != -1) {
            dp[i] = std::min(dp[i], dp[last[i]]+1);
        }
    }

    std::cout<<dp[n-1];
    return 0;
}