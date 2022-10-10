#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
int ans;
int target;
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        target = targetSum;
        dfs({}, root);
        return ans;
    }

    void dfs(vector<long> nums, TreeNode* root){
        if(root == nullptr) return ;
        nums.push_back(root->val);
        fun(nums);
        dfs(nums, root->left);
        dfs(nums, root->right);
    }
    void fun(vector<long>& nums){
        int i = nums.size() - 1;
        long tmp = 0;
        while(i >= 0){
            tmp += nums[i--];
            if(tmp == target) ans ++;
        }
    }
    // void fund(vector<long>& nums){
    //     int i = nums.size() - 2;
    //     long tmp = nums.back();
    //     while(i >= 0){
    //         if(tmp - nums[i--] == target) ans ++;  
    //     }
    // }
};