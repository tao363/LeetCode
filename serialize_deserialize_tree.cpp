#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string seria = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            seria.push_back('#');
            return;
        }
        seria.push_back('0' + root->val);
        serialize(root->left);
        serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};