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
    int findRepeatNumber(vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == nums[nums[i]] && i != nums[nums[i]]){
                return nums[i];
            }
            else {
                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[nums[i]] = tmp;
            }
        }
        return 0;
    }
};