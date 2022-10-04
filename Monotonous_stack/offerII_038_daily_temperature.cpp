#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sta;
        vector<int> ans(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i){
            while(!sta.empty() and temperatures[sta.top()] < temperatures[i]){
                ans[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        return ans;
    }
};