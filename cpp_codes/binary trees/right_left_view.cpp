#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
        vector<int> rightSideView(TreeNode* root){
            vector<int> res;
            int level=0;
            solveRight(root,level,res);
            return res;
        }
        void solveRight(TreeNode* root,int level,vector<int> &res){
            if(root==NULL) return;
            if(level==res.size()){
                res.push_back(root->val);
            }
            solveRight(root->right,level+1,res);
            solveRight(root->left,level+1,res);
        }

        vector<int> leftSideView(TreeNode* root){
            vector<int> res;
            int level=0;
            solveLeft(root,level,res);
            return res;
        }
        void solveLeft(TreeNode* root,int level,vector<int> &res){
            if(root==NULL) return;
            if(level==res.size()){
                res.push_back(root->val);
            }            
            solveLeft(root->left,level+1,res);
            solveLeft(root->right,level+1,res);
        }

};
void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

        // Get the Right View traversal
    vector<int> rightView = solution.rightSideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftSideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;
}


