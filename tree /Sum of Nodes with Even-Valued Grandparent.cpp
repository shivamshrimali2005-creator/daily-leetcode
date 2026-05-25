class Solution {
public:
    void f(TreeNode *root,int &sum){

        if(root == NULL) return;

        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left) sum += root->left->left->val;
                if(root->left->right) sum += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) sum += root->right->left->val;
                if(root->right->right) sum += root->right->right->val;
            }
        }

        f(root->left,sum);
        f(root->right,sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        
        int sum = 0;
        f(root,sum);

        return sum;
    }
};
