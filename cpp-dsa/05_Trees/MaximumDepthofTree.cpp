/*
 * Leetcode : 104
 * Pattern: Breadth-First Search, Depth-First Search, Recursion, Queue, Binary Tree
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Method: Calculate the maximum depth of the binary tree.
 * Definition for a binary tree node.
*/

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};

int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right)+1;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<"Max Depth: "<<maxDepth(root);
    return 0;
}
