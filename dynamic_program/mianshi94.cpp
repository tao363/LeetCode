#include <iostream>
#include <vector>

using namespace std;

/*
                    最少回文分割
    先记录所有的回子串；
    dp[i] : 表示S[0.....i-i] 时的最少的分割次数
    当bl[j+1][i-1] 是回文子串，
        dp[i] = min(dp[i], dp[j-1] + 1);
*/

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> bl(len, vector<bool>(len, false));
        //先记录组成回文串的子串
        for(int i = 0; i < len; ++i){
            for(int j = 0; j <= i; ++j){
                char c1 = s[i], c2 = s[j];
                if(c1 == c2 and (i <= j+1 or bl[j+1][i-1])){
                    bl[j][i] = true;
                }
            }
        }
        //  根据前面的数据进行操作，进行递推，动态规划过程
        vector<int> dp(len);
        for(int i = 0; i < len; ++i){
            if(bl[0][i])    dp[i] = 0;
            else{
                dp[i] = i;
                for(int j = 1; j <= i; ++j){
                    if(bl[j][i]){
                        dp[i] = min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }
        return dp[len - 1];
    }
};


