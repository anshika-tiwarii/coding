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
    bool areSubtreesSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1==NULL || root2==NULL){
            return root1==root2;
        }
        return (root1->val==root2->val) && areSubtreesSymmetric(root1->left,root2->right)
        && areSubtreesSymmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return areSubtreesSymmetric(root->left,root->right);
    }
};
void printInorder(TreeNode* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    Solution solution;

    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }

}
