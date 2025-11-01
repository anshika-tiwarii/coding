#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if(root==NULL) return result;
        queue<pair<Node*,int>> todo;
        map<int,int> nodes;
        todo.push({root,0});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            Node* node=p.first;
            int vertical=p.second;
            if(nodes.find(vertical)==nodes.end()) nodes[vertical]=node->data;
            
            if(node->left){
                todo.push({node->left,vertical-1});
            }
            if(node->right){
                todo.push({node->right,vertical+1});
            }
        }
        
        for(auto p:nodes){
            result.push_back(p.second);
        }
        return result;
    }
};
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =solution.topView(root);

    // Print the result
    cout << "Top View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }

    return 0;
}