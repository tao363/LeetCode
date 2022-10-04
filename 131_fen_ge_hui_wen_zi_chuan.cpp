#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<string>> ans;
vector<string> tmp;
    bool Is(string s, int l, int r){//判断是否为回文子串
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++, r--;
        }
        return true;
    }
    void dfs(string s, int l){
        if(l >= s.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int r = l; r< s.size(); ++r){
            if(Is(s, l, r)){
                string ss = s.substr(l,r-l+1);
                tmp.push_back(ss);
                dfs(s, r+1);        //递归
                tmp.pop_back();     //回溯
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return ans;
    }
};