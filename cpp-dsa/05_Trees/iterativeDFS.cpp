/*
 * Leetcode : 94
 * Pattern: Binary Tree, Depth-First Search,Stack
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Method: Iterative Approach
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void iterativeDFs(TreeNode* root){
   if(root==nullptr)return;
   stack<TreeNode*> callStack;
   callStack.push(root);
   while(!callStack.empty()){
    TreeNode* curr = callStack.top();
    callStack.pop();
    cout<<curr->val<<" ";
    if(curr->right){callStack.push(curr->right);}
    if(curr->left){callStack.push(curr->left);}
   }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    iterativeDFs(root);
    return 0;
}