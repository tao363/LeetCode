#include <iostream>
#include <stack>
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
/*************************************前序**************************************/
vector<int> Dfs;
//                                  DFS递归版
void Pre_dfs(TreeNode* root){
    if(root == nullptr) return ;
    Dfs.push_back(root->val);
    Pre_dfs(root->left);
    Pre_dfs(root->right);
}
//                                  循环迭代版
void Pre_bc(TreeNode* root){
    stack<TreeNode*> que;
    while(root != nullptr or !que.empty()) {
        if(root != nullptr) {                  //还没到叶子节点，就一直压栈，然后将往左子节点走
            cout << root->val << " ";         //只有在入栈的时候取数据就行
            que.push(root);
            root = root->left;
        }
        else{                                   //在叶子节点的时候，就需要取栈中的节点
            root = que.top();
            root = root->right;
            que.pop();
        }
    }

}

/*************************************中序**************************************/

void inorder_dfs(TreeNode* root){
    if(root == nullptr) return;
    Pre_dfs(root->left);
    cout << root->val << endl;
    Pre_dfs(root->right);
}

void Inorder(TreeNode* root){
    stack<TreeNode*> sta;
    while(root != nullptr or !sta.empty()){
        if(root != nullptr){                //刚拿到的节点的时候就直接将其压栈
            sta.push(root);
            root = root->left;
        }
        else{                               //当到达叶子节点的时候就说明要取值了，并将root 往右节点移动
            root = sta.top();
            sta.pop();
            cout << root->val << endl;
            root = root->right;
        }
    }
}
/*************************************后序**************************************/
void Post_dfs(TreeNode* root){
    if(root == nullptr) return ;
    Post_dfs(root->left);
    Post_dfs(root->right);
    cout << root->val << endl;
}

void Post_Order(TreeNode* root){
    stack<TreeNode*> sta;
    TreeNode* vis = nullptr;                //用来记录前一个被访问的节点
    while(root != nullptr or !sta.empty()){
        if(root != nullptr){                //首先一直往左边入栈
            sta.push(root);
            root = root->left;
        }
        else{                              
            root = sta.top();
            if(root->right == nullptr or root->right == vis){   //当前节点的右节点已经被遍历，或者是右节点为空，则可以输出的当前节点
                cout<< root->val << " ";
                sta.pop();
                vis = root;                                     //最新遍历的节点为当前节点
                root = nullptr;                                 //遍历完后就将当前节点设置  为空
            }
            else{                                               //如果还有右节点，就继续往右进行入栈操作
                root = root->right;
            }
        }
    }
}

