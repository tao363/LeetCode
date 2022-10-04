#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<string> ans;
    void dfs(string& s, int begin, int pointuNum){
        if(pointuNum == 3){
            if(isValid(s,begin,s.size()-1)){
                ans.push_back(s);
            }
            return ;  
        }
        for(int i = begin; i < s.size(); ++i){
            if(isValid(s, begin, i)){
                s.insert(s.begin()+i+1, '.');
                pointuNum ++;
            }
            dfs(s, i+2, pointuNum);
            pointuNum --;
            s.erase(s.begin()+i+1);
        }

    }
    bool isValid(const string& s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' and start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; ++i){
            if(s[i] >'9' or s[i] < '0'){
                return false;
            }
            num = num*10 + (s[i] - '0');
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return ans;
        dfs(s, 0, 0);
        return ans;
    }
};