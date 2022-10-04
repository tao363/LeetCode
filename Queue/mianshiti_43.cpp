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
 
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        m_root = root;
        if(root != nullptr){
            m_que.push(root);
            while(!m_que.empty()){          
                TreeNode* node = m_que.front();
                if(node->left)  m_que.push(node->left);                 //当左子树存在的时候需要先将左子树入队。
                if(node->left == nullptr || node->right == nullptr){
                    break;
                }
                m_que.pop();
                m_que.push(node->right);
            }
        }             
    }
    
    int insert(int v) {
        TreeNode *node = m_que.front();
        if(node->left == nullptr){
            node->left = new TreeNode(v);
            m_que.push(node->left);
        }
        else{
            m_que.pop();
            node->right = new TreeNode(v);
            m_que.push(node->right);
        }
        return node->val;
    }
    
    TreeNode* get_root() {
        return m_root;
    }
private:
    queue<TreeNode*> m_que; //用来存放左右子节点满的情况
    TreeNode* m_root;
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    CBTInserter solve(root);
    solve.insert(3);
    solve.insert(4);
    solve.get_root();
}