class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1);
        for(auto x : dislikes){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);

        for(int i=0;i<n;i++){
            if(color[i] != -1) continue;

            queue<int> q;
            q.push(i); 
            color[i] = 0;

            while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto x : adj[node]){
                if(color[x] == -1){
                    color[x] = (color[node] + 1) % 2;
                    q.push(x);
                }
                else if(color[x] == color[node]) return 0;
            }
        }
        }

        return 1;
    }
};
