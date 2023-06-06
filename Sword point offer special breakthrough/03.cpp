#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 使用集合或者使用map先进行存储，然后在进行判断
class Solution{
public:
    int findRepeatNumber(vector<int>& nums){
        unordered_map<int, int> Map;
        for(int num: nums){
            if(Map[num] != 0){
                return num;
            }
            else {
                Map[num] += 1;
            }
        }
        return 0;
    }
};

// 直接使用交换的方法

class Solution{
public:
int countRange(const vector<int>& nums, int start, int end) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= start && nums[i] <= end) {
            count++;
        }
    }
    return count;
}

int findRepeatNumber(vector<int>& nums) {
    int start = 1, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int count = countRange(nums, start, mid);
        if (start == end) {
            if (count > 1) {
                return start;
            } else {
                break;
            }
        }
        if (count > mid - start + 1) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}
};