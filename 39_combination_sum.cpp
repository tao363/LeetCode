#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int sum, int begin){  //这里使用begin 的原因是所得的结果是一个数组，而不是排序
        if(sum == target){
            ans.push_back(tmp);
            return;
        }
        for(int i= begin; i < candidates.size(); ++i){
            if(sum + candidates[i] <= target){
                tmp.push_back(candidates[i]);
                dfs(candidates, target, sum + candidates[i], i);
                tmp.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target,0,0);
        return ans;
    }
};