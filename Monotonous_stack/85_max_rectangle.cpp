#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n);
        //对于矩阵中的每一行都当做一个高度进行计算
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else heights[j] = 0;
            }
            ans = max(ans, maxArea(heights));
        }
        return ans;
    }
    //下面这个就是84的原函数
    int maxArea(vector<int>& heights){
        int ans = 0;
        heights.push_back(-1);
        stack<int> sta;
        for(int i = 0; i < heights.size(); ++i){
            while(!sta.empty() and heights[i] < heights[sta.top()]){
                int height = heights[sta.top()];
                sta.pop();
                int left = sta.empty() ? -1: sta.top();
                ans = max(ans, height * (i - left - 1));
            }
            sta.push(i);
        }
        heights.pop_back();
        return ans;
    }
};