#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);
        return  to_string(root->val) + "," + leftStr + "," + rightStr;
    }
    vector<string> split(string& s, char c){                //按照','对字符串进行分割
        int i = 0;
        int pre = 0;
        vector<string> ans;
        string str;
        while(i < s.size()){
            if(s[i] == ','){
                ans.push_back(str);
                str.clear();
            }
            else{
                str.push_back(s[i]);
            }
            i++;
        }
        if(!str.empty()) ans.push_back(str);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        vector<string> tmp = split(data, ',');
        return fun(tmp);
    }
    int i = 0;                              //在反序列化的操作中，需要注意结点的位置。
    TreeNode* fun(vector<string>& strs){            //在实际的开发中多使用引用，可以极大的减少运行时间
        string s = strs[i++];
        if(s == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = fun(strs);
        root->right = fun(strs);
        return root;
    }
};