#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        priority_queue<int> prio;
        int total = 0;
        for(auto cour : courses){
            if(total + cour[0] <= cour[1]){
                prio.push(cour[0]);
                total += cour[0];
            }
            else if(!prio.empty() and prio.top() > cour[0]){
                total -= prio.top();
                total += cour[0];
                prio.pop();
                prio.push(cour[0]);
            }
        }
        return prio.size();
    }
};