/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,TreeNode *> mp;
    void inorder(TreeNode *root){
        if(root == NULL) return;

        if(root->left != NULL) mp[root->left] = root;
        inorder(root->left);

        if(root->right != NULL) mp[root->right] = root;
        inorder(root->right);
    }

    void bfs(TreeNode *target,vector<int> &ans,unordered_set<TreeNode *> &visited,int k){

        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);

        while(!q.empty()){
            int size = q.size();
            if(k == 0) break;

            for(int i=0;i<size;i++){
                TreeNode *t = q.front();
                q.pop();

                if(t->left && !visited.count(t->left)){
                    q.push(t->left);
                    visited.insert(t->left);
                }

                if(t->right && !visited.count(t->right)){
                    q.push(t->right);
                    visited.insert(t->right);
                }

                if(mp.count(t) && !visited.count(mp[t])){
                    q.push(mp[t]);
                    visited.insert(mp[t]);
                }
            }
            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        inorder(root);

        vector<int> ans;
        unordered_set<TreeNode *> visited;
        bfs(target,ans,visited,k);

        return ans;
    }
};
