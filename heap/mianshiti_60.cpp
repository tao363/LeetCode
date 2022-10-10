#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occ;
        for(int num : nums){
            occ[num] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for(auto& num: occ){
            if(q.size() < k){
                q.push(num);
            }
            else{
                if(q.top().second < num.second){
                    q.pop();
                    q.push(num);
                }
            }
        }
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = (q.top().first);
            q.pop();
        }
        return ans;
    }
};