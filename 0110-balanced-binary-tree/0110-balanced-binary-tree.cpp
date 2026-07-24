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
    //optimal code
    bool isBalanced(TreeNode* root) {
        
        if(balanced(root)==-1) return false;
        return true;
    }
    int balanced(TreeNode* root){
        if(!root) return 0;
        int left = balanced(root->left);
        if(left==-1) return -1;
        int right=balanced(root->right);
        if(right==-1) return -1;
        if(abs(left-right)>1)
            return -1;
        return (1+max( left,right)); 
        
    }
};