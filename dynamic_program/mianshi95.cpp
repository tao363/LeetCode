#include<iostream>
#include <vector>
using namespace std;

/*
    dp[i][j] : text[0.....i] 和text2[0....j] 的最长公共子序列
    if  text1[i] == text2[j] 
        dp[i][j] = dp[i-1][j-1] + 1;
    else   
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        if(s1 == 0 or s2 ==0) return 0;
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
        for(int i = 1; i <= s1; ++i){
            for(int j = 1; j <= s2; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
};