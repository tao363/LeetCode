#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        if(nums.size() == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(2,0));
        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[0][i%2] = max(dp[0][(i-1%2)], dp[1][(i-1)%2]);       //f(i)
            dp[1][i%2] = nums[i] + dp[0][(i-1)%2];                  //g(i)
        }
        return max(dp[0][(nums.size() - 1)%2], dp[1][(nums.size() - 1)%2]);
    }
};