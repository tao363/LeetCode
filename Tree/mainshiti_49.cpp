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
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int val){
        if(root == nullptr) return;                               //当只有左子节点或者右子节点的时候就需要进行提前判断
        if(root->left == nullptr and root->right == nullptr ){    //当到达叶子结点的时候就需要停止递归
            ans = ans + val * 10 + root->val;
            return;
        }
        dfs(root->left, val *10 + root->val);
        dfs(root->right, val*10+root->val);
    }
};