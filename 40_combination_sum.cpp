#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int begin, int sum){
        if(sum == target){
            ans.push_back(tmp);
            return ;
        }
        for(int i = begin; i < candidates.size(); ++i){
            if(sum + candidates[i] <= target){
                tmp.push_back(candidates[i]);
                dfs(candidates, target, i+1, sum + candidates[i]);                  //递归+ 回溯
                tmp.pop_back();                                                     //回溯回来修改值
                while(i+1 < candidates.size() and candidates[i+1] == candidates[i]){//去重的过程
                    i++;
                }
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};