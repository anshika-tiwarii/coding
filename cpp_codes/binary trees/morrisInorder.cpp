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

class Solution {
public:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     inOrder(root,ans);
    //     return ans;
    // }
    // private:
    // void inOrder(TreeNode* root, vector<int> &ans){
    //     if (root==NULL){
    //         return ;
    //     }         
    //     inOrder(root->left,ans);
    //     ans.push_back(root->val);
    //     inOrder(root->right,ans);
        
    // }

    vector <int> inorderTraversal(TreeNode* root){
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur!=NULL){
            if (cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};
int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    
    vector<int> inorder = sol.inorderTraversal(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;
}
