#include<iostream>
#include<queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    void flatten(TreeNode* root){
        if(nullptr == root){
            return;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = nullptr;
        

    }
};

class Solution1 {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* root_temp = root;
        queue<TreeNode*> que1;
        stack<TreeNode*> stk1;
        stk1.push(root);
        while(!stk1.empty()){
            que1.push(stk1.top());
            TreeNode* tmp = stk1.top();
            stk1.pop();
            // cout << tmp->val << " " ;
            if(tmp->right != nullptr){
                stk1.push(tmp->right);
            } 
            if(tmp->left != nullptr) {
                stk1.push(tmp->left);
            }
        }
        // cout << endl;
        que1.pop();
        while(!que1.empty()){
            root_temp->right = que1.front();
            root_temp->left = nullptr;
            que1.pop();
            root_temp = root_temp->right;
        }
    }

};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution so;
    so.flatten(root);

}