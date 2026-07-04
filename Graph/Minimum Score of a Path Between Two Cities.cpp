class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis,int &ans){

        vis[node] = 1;

        for(auto x : adj[node]){
            ans = min(ans,x.second);
            if(!vis[x.first]){
                vis[x.first] = 1;
                dfs(x.first,adj,vis,ans);
            }
        }

    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x : roads){
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int> vis(n+1,0);
        int ans = INT_MAX;

        dfs(1,adj,vis,ans);

        return ans;
    }
};
