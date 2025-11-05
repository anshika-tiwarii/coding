#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    TreeNode* markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track,int start) {
        queue<TreeNode*> queue;
        TreeNode* startNode;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            if (current->val==start) startNode=current;
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        return startNode;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* startNode=markParents(root, parent_track,start);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(startNode);
        visited[startNode] = true;
        int mins = 0;
        while (!queue.empty()) {
            int size = queue.size();
            bool burned = false;
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left]) {
                    burned=true;
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    burned=true;
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    burned=true;
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }                
            }
            if(burned) mins++;
        }
        return mins;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    // Create solution object
    Solution sol;

    // Set target node to burn from
    int target = 1;

    // Print the minimum time to burn the tree
    cout << "Minimum time to burn the tree: " << sol.amountOfTime(root, target) << endl;

   
}