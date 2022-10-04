#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//递推公式
/*
if(s[i] === s[j])
    dp[i][j] = dp[i-1][j+1] + 2;
else
    判断  s[i+1,....,j] 和 s[i,...,j-1]哪个回文子序列更长。
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

dp[i][j] 表示从s[i,...j]的最长回文子序列
*/



class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int size = s.size();
        if (size == 1)
        {
            return 1;
        }
        vector<vector<int>> dp(size, vector<int>(size,0));
        //base case
        for(int i = 0; i < size; ++i){
            dp[i][i] = 1;
        }
        //反向遍历保证正确的状态转移
        for (int i = size - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][size -1];
    }
};

int main()
{
    Solution so;
    cout << so.longestPalindromeSubseq("cbbd");
}