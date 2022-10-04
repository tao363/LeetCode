#include <iostream>
#include <vector>
#include <math.h>
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
    int countNodes(TreeNode* root) {
        TreeNode* l = root, *r = root;
        int hl = 0, hr = 0;
        while(l != nullptr){
            l = l->left;
            hl++;
        }
        while(r != nullptr){
            r = r->right;
            hr++;
        }
        if(hr == hl){                               //当左右高度相等的时候，就相当于该子树是一个满二叉树，此时的树节点数量是一个指数级的
            return (int)pow(2, hl) - 1;
        }
        return 1+countNodes(root->left) + countNodes(root->right);  //当不是满二叉树的时候，就使用的常规的树节点的计算方法
    }
};