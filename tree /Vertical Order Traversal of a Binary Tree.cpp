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
    void f(TreeNode *root,int row,int col,map<int,vector<pair<int,int>>> &mp){

        if(root == NULL) return;

        mp[col].push_back({row,root->val});

        f(root->left,row+1,col-1,mp);
        f(root->right,row+1,col+1,mp);
    }
  
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pair<int,int>>> mp;
        f(root,0,0,mp);

        vector<vector<int>> v;
        for(auto x : mp){
            sort(x.second.begin(),x.second.end());
            vector<int> temp;
            for(auto y : x.second){
                temp.push_back(y.second);
            }
            v.push_back(temp);
        }

        return v;
    }
};
