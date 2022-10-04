#include <iostream>
#include <queue>

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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;
        while(!que.empty()){
            int size = que.size();
            int Max = que.front()->val;
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                Max = max(Max, node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ans.emplace_back(Max);
        }
        return ans;
    }
};