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
    unordered_map<TreeNode *,TreeNode *> mp;
    TreeNode *k = NULL;

    void inorder(TreeNode *root,int &start){

        if(root == NULL) return;

        if(root->val == start) k = root;

        if(root->left) mp[root->left] = root;
        inorder(root->left,start);

        if(root->right) mp[root->right] = root;
        inorder(root->right,start); 
    }

    int amountOfTime(TreeNode* root, int start) {
        
        inorder(root,start);

        set<TreeNode *> visited;

        queue<TreeNode *> q;
        q.push(k);
        visited.insert(k);

        int time = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto root = q.front();
                q.pop();

                if(root->left && !visited.count(root->left)){
                    q.push(root->left);
                    visited.insert(root->left);
                }

                if(root->right && !visited.count(root->right)){
                    q.push(root->right);
                    visited.insert(root->right);
                }

                if(mp.count(root) && !visited.count(mp[root])){
                    q.push(mp[root]);
                    visited.insert(mp[root]);
                }                
            }
            time++;
        }

        return time-1;
    }
};
