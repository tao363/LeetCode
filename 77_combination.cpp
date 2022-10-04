#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    void backtracking(int n, int k, int begin) {
        if(nums.size() == k){
            ans.push_back(nums);
            return ;
        }
        for(int i = begin; i <= n - (k - nums.size()); ++i){
            nums.push_back(i);
            backtracking(n,k,i+1);
            nums.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return ans;
    }
};