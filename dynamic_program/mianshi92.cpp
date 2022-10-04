#include <iostream>
#include <vector>

using namespace std;

/*
    当最后一个位置为0的时候：f(i) = f(i-1) + s[i] == '0' ? 0: 1
    当最后一个位置为1的时候：g(i) = min(f(i-1), g(i-1)) + s[i] == '1' ? 0: 1
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(2, vector<int>(2,0));
        char c = s[0];
        dp[0][0] = (c == '0' ? 0 : 1);
        dp[0][1] = (c == '1' ? 0 : 1);
        for(int i = 1; i< s.size(); ++i){
            c = s[i];
            int pre1 = dp[0][(i-1)%2];
            int pre2 = dp[1][(i-1)%2];
            dp[0][i%2] = pre1 + (c == '0' ? 0 : 1);
            dp[1][i%2] = min(pre1, pre2) + (c == '1' ? 0 : 1);
        }
        return min(dp[0][(s.size() - 1) % 2], dp[1][(s.size() - 1) % 2]);
    }
};