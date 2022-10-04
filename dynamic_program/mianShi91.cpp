#include <iostream>
#include <vector>
#include <string>
using namespace std;
//                              粉刷房子
/*
    当前选择红色    r[i] = min(g(i-1), b(i-1)) + costs[i][0];
    当前选择绿色    g[i] = min(r(i-1), b(i-1)) + costs[i][1];
    当前选择蓝色    b[i] = min(r(i-1), g(i-1)) + costs[i][2];
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        vector<vector<int> > dp(3, vector<int>(2));
        for(int i = 0; i<3; ++i){
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < costs.size(); ++i){
            for(int j = 0; j < 3; ++j){
                int pre1 = dp[(j + 2) % 3][(i-1)%2];
                int pre2 = dp[(j + 1) % 3][(i-1)%2]; 
                dp[j][i%2] = min(pre1, pre2) + costs[i][j];
            }
        }
        int last = (costs.size() - 1) % 2;
        return min(dp[0][last], min(dp[1][last], dp[2][last]));
    }
};