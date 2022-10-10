#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 最小堆
        auto cmp = [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        //先取一整行，放入小根堆中，因为刚开始的时候两个数组中的起始位置肯定是最小的组合，
        // 然后再进行移动即可
        for (int i = 0; i < k && i < nums1.size(); ++i) {
            heap.push({i, 0});
        }
        vector<vector<int>> ret;
        while (k-- > 0 && !heap.empty()) {
            auto ids = heap.top();
            heap.pop();
            ret.push_back({nums1[ids.first], nums2[ids.second]});

            if (ids.second < nums2.size() - 1) {
                heap.push({ids.first, ids.second + 1});
            }
        }

        return ret;
    }
};