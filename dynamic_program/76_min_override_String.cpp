#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, windows;
        for(char c: t) need[c] ++;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while(right < s.size()){                        //最终的条件
            char c = s[right];
            right++;                                    //右窗口移动
            if(need.count(c)){
                windows[c] ++;
                if(windows[c] == need[c]) valid++;
            }
            while(valid == need.size()){                //移动左边窗口，当满足条件后再进行移动
                if(right - left < len){                 //只有当小于之前的长度的时候，才进行计算长度
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left ++;
                if(need.count(d)){
                    if(windows[d] == need[d]){
                        valid--;
                    }
                    windows[d]--;
                }
            }
        }
        return len == INT_MAX? "": s.substr(start, len);
    }
};