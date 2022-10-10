#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<char> v;
int n;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* CreatTree(vector<vector<int>>& nums, vector<TreeNode*>& created){
   for(int i = 0; i < n; ++i){
      if(nums[i][0] < nums[i][1]){ //左
         if(created[nums[i][0]] == nullptr){
            created[nums[i][0]] = new TreeNode(nums[i][0]);
         }
         if(created[nums[i][1]] == nullptr){
               created[nums[i][1]] = new TreeNode(nums[i][1]);
         }    
         created[nums[i][0]]->left = created[nums[i][1]];
      }
      else{//右边
         if(created[nums[i][1]] == nullptr){
            created[nums[i][1]] = new TreeNode(nums[i][1]);
         }
         if(created[nums[i][0]] == nullptr){
            created[nums[i][0]] = new TreeNode(nums[i][0]);
         }    
         created[nums[i][1]]->right = created[nums[i][0]];
      }
   }
   return created[1];
}
int dfs(TreeNode* root){
   if(root == nullptr) return 0;
   //if(root->left == nullptr and root->right == nullptr) return 1;
   int leftval = dfs(root->left);
   int rightval = dfs(root->right);
   int sum = leftval + rightval;
   if(sum & 1){
      v[root->val] = 'R';
   }
   else {
      v[root->val] = 'B';
      // sum --;
      sum++;
   }
   return sum;
}
int main(){
   cin >> n;
   v = vector<char> (n+1, 'B');
   vector<TreeNode*> created = vector<TreeNode*> (n+1, nullptr);
   vector<vector<int>> nums(n, vector<int>(2,0));
   int x, y;
   for(int i = 0; i < n-1; ++i){
      cin >> x >> y;
      nums[i][0] = x;
      nums[i][1] = y;
   }
   TreeNode* root = CreatTree(nums, created);
   dfs(root);
   for(int i = 1; i <= n; ++i){
      cout << v[i];
   }
   return 0;
}