#include<iostream>
#include<vector>
using namespace std;

/*
dp[i][j] 表示  s[i,....j] 最少插入次数构成回文子串
if s[i] == s[j]
    dp[i][j] = dp[i+1][j-1];
else
    因为
    dp[i][j] = min(dp[i+1][j]+1, dp[i][j-1]+1);
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = n - 2; i >= 0; --i){
            for(int j = i + 1; j < n; ++j){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j-1]+1);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main(){

}