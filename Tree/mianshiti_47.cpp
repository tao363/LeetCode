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
    TreeNode* pruneTree(TreeNode* root) {
        return fun(root);    
    }
    TreeNode* fun(TreeNode* root){
        if(root == nullptr) return nullptr;
        root->left = fun(root->left);
        root->right = fun(root->right);
        if(root->val == 0 and root->left == nullptr and root->right == nullptr){
            return nullptr;
        }
        return root;
    }
};