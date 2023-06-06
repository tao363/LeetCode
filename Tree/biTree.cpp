#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void postOrder(TreeNode* root){
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    stk1.push(root);
    while(!stk1.empty()){
        stk2.push(stk1.top());
        TreeNode* tmp = stk1.top();
        stk1.pop();
        if(tmp->left){
            stk1.push(tmp->left);
        }
        if(tmp->right){
            stk1.push(tmp->right);
        }
    }
    while(!stk2.empty()){
        cout << stk2.top()->value << " ";
        stk2.pop();
    }
    cout << endl;
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 后序遍历二叉树
    cout << "后序遍历结果：" << endl;
    postOrder(root);

    // 释放内存
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}