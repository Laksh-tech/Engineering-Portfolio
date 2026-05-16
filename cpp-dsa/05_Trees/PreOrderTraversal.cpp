/**
 * Leetcode : 94
 * Pattern: Binary Tree, Depth-First Search,Stack
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Method: Recursive Approach
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
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PreOrderTraversal(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->val;
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    PreOrderTraversal(root);
    return 0;
}