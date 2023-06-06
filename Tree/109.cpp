#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 //链表中寻找中位数的节点的方法可以使用快慢指针的方法，慢指针一次移动一个节点，但是快指针则是一次移动两个节点的位置。当快指针到达尾部的时候慢指针的位置就是中位数的节点位置。
class SolutionPre {
    //使用前序遍历的方法，先寻找到对应链表节点中的值，然后构造出对应的二叉树节点，然后由该二叉树结点依次进行递归操作。
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        int size = nums.size();
        return fun(nums, 0, nums.size()-1);
    }
    TreeNode* fun(vector<int>& nums, int lhs, int rhs){
        if(lhs > rhs) return nullptr;
        int mid = (lhs + rhs)/2;
        TreeNode* tmp = new TreeNode(nums[mid]);
        tmp->left = fun(nums, lhs, mid - 1);
        tmp->right = fun(nums, mid + 1, rhs);
        return tmp;
    }
};

class SolutionIn{
public:
    int getLength(ListNode* head){
        int size = 0;
        while(head != nullptr){
            size++;
            head = head->next;
        }
        return size;
    }
    TreeNode* treeBuild(ListNode*& head, int lhs, int rhs){
        if(lhs > rhs) return nullptr;
        int mid = (lhs + rhs)>>1;
        TreeNode* root = new TreeNode();
        root->left = treeBuild(head, lhs, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = treeBuild(head, mid + 1, rhs);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        treeBuild(head, 0, length - 1);
    }
};