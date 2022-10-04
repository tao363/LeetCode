#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//代码详解
/*
if s1[i] == s2[j]
    啥都沒做（skip）
    i，j 同时向前移动
else:
    三选一：
        插入（insert)
        删除（delect）
        替换（replace）
*/
int Min(int a, int b, int c)
{
    int tmp = a;
    tmp = min(tmp, b);
    tmp = min(tmp, c);
    return tmp;
}
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // base case
        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = Min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution so;
    cout << so.minDistance("bagg", "bag") << endl;
}