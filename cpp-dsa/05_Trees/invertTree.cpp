/*
 * Leetcode : 226
 * Problem : Given the root of a binary tree, invert the tree, and return its root.
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
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void PreorderTraversal(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->val;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right); 
}
TreeNode* invertTree(TreeNode* root){
    if(root==nullptr){
        return nullptr;
    }
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    PreorderTraversal(root);
    cout<<endl;
    invertTree(root);
    PreorderTraversal(root);
    return 0;

}