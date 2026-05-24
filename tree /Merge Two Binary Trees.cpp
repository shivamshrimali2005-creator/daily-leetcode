class Solution {
public:
    TreeNode* f(TreeNode *root1,TreeNode *root2){

        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        TreeNode *root = new TreeNode(root1->val + root2->val);

        root->left = f(root1->left,root2->left);
        root->right = f(root1->right,root2->right);

        return root;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        return f(root1,root2);
    }
};
