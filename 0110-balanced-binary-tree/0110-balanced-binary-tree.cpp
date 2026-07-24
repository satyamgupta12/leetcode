/**
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
class Solution {
public:
    int flag=0;
    bool isBalanced(TreeNode* root) {
        balanced(root);
        if(flag==1) return false;
        return true;
    }
    int balanced(TreeNode* root){
        if(!root) return 0;
        int left = balanced(root->left);
        int right=balanced(root->right);
        if(abs(left-right)>1)
            flag=1;
        return (1+max( left,right)); 
        
    }
};