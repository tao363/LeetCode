#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
  


*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); ++i){
            map[arr[i]] = i; 
        }
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        int ans = 2;
        for(int i = 1; i < arr.size(); ++i){
            for(int j = 0; j < i; ++j){
                int k = -1;
                if(map.count(arr[i] - arr[j])){
                    k = map[arr[i] - arr[j]];
                }
                dp[i][j] = k>=0 and k < j? dp[j][k] + 1 : 2;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};