#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> tmp;
vector<vector<int>> ans;
    void dfs(int k, int n, int begin,int sum){
        if(tmp.size() == k and sum == n){
            ans.push_back(tmp);
            return ;
        }
        for(int i = begin; i <= 9; ++i){
            if(sum + i <= n){   //减枝过程，
                tmp.push_back(i);
                dfs(k,n,i+1,sum+i);
                tmp.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n,1,0);
        return ans;
    }
};