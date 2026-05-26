/*
 * Leetcode : 101
 * Pattern: Breadth-First Search, Depth-First Search, Recursion, Queue, Binary Tree
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Method: Assume left and right subtrees are mirror images of each other, then the tree is symmetric.
 * Definition for a binary tree node.
  */
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};

#include<iostream>
#include<queue>
using namespace std;

bool isSymmetric(TreeNode* root){
    if(root==nullptr) return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        TreeNode* t1 = q.front();q.pop();
        TreeNode* t2 = q.front();q.pop();
        if(t1 == nullptr && t2 == nullptr) continue;
        if(t1 ==nullptr || t2 == nullptr) return false;
        if(t1->val != t2->val) return false;
        q.push(t1->left);
        q.push(t2->right);
        
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}

