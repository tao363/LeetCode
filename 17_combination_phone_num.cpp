#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(string s, int begin, unordered_map<char,string>& v,int size,string digits){
        //当满足条件时，将结果放入内存中
        if(s.size() == size){
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < v[digits[begin]].size(); ++i){
            if(begin < size){
                dfs(s+v[digits[begin]][i],begin+1,v,size,digits);   //递归过程，因为在传值的时候使用的“+”，因此这个也是用了回溯。
            }    
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        unordered_map<char,string> v;
        v['2'] = "abc";
        v['3'] = "def", v['4'] = "ghi", v['5'] = "jkl",v['6'] = "mno", v['7'] = "pqrs", v['8'] = "tuv",v['9']  = "wxyz";
        string s = "";
        dfs(s,0,v,digits.size(),digits);
        return ans;
    }
};