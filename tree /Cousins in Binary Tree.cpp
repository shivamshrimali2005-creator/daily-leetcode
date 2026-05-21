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
    bool f(TreeNode *root,int a,int b){

        if(root == NULL) return 0;

        if(root->left && root->right){
            if(root->left->val == a && root->right->val == b) return 1;
            if(root->right->val == a && root->left->val == b) return 1;
        }

        return f(root->left,a,b) || f(root->right,a,b);
    }


    bool isCousins(TreeNode* root, int x, int y) {

        queue<TreeNode *> q;
        q.push(root);

        int l1 = -1;
        int l2 = -1;

        int level = 0;

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();

                if(temp->val == x) l1 = level;
                if(temp->val == y) l2 = level;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            level++;
            if(l1 != l2) return 0;
            if(l1 != -1 && l2 != -1) break;
        }

        return !f(root,x,y);
    }
};
