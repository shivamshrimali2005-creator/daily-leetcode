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
    vector<vector<int>> paths;

    void f(TreeNode *root,vector<int> p){

        if(root == NULL) return;

        p.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            paths.push_back(p);
            return;
        }

        f(root->left,p);
        f(root->right,p);

    }

    int maxAncestorDiff(TreeNode* root) {
        
        vector<int> p;
        f(root,p);

        int ans = INT_MIN;

        for(int i=0;i<paths.size();i++){
            sort(paths[i].begin(),paths[i].end());
            int last_index = paths[i].size()-1;
            ans = max(ans,paths[i][last_index]-paths[i][0]);
        }

        return ans;
    }
};
