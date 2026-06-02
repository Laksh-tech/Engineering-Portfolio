/*
 * Leetcode : 102
 * Pattern: Binary Tree, Level-Order Traversal, Queue
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Method: Iterative Approach
 * Definition for a binary tree node.
 *  */
#include<iostream>
#include<queue>
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

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> levels;
    if(root==nullptr)return levels;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> v;
        for(int i = 0; i<levelSize;i++){
        TreeNode* curr = q.front();q.pop();
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
        v.push_back(curr->val);
        }
        levels.push_back(v);
    }
    return levels;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    levelOrder(root);
    return 0;
}