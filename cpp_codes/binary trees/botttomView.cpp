#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<int> bottomView(Node *root) {
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
            nodes[vertical]=node->data;
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

    // Get the Bottom View traversal
    vector<int> bottomView =solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }

    
}