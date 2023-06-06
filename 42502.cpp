#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp)%1000000007;
    }
private:
    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
        // 终止条件
        if (l >= r) return 0;
        // 递归划分
        int m = (l + r) / 2;
        int res = (mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp))%1000000007;
        // 合并阶段
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++)
            tmp[k] = nums[k];
        for (int k = l; k <= r; k++) {
            if (i == m + 1)
                nums[k] = tmp[j++];
            else if (j == r + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res = (res + m - i + 1); // 统计逆序对
            }
        }
        return res;
    }
};

int minDeletions(string s) {
    int res = 0;
    unordered_map<char, int> freq;
    for (char c : s) {
        if(freq.count(c) != 0){
            res++;
        }
        else freq[c] = 1;
    }
    return res;
}
int main(){
    string s = "abab";
    cout << minDeletions(s) << endl;
    return 0;
}