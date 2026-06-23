class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adj(n);
        for(auto x : relations){
            int u = x[0];
            int v = x[1];

            adj[u-1].push_back(v-1);
        }

        // KAHN'S ALGO
        vector<int> indegree(n,0);
        for(auto x : adj){
            for(auto y : x){
                indegree[y]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> prevtime(n,0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);

                prevtime[x] = max(prevtime[x],prevtime[node] + time[node]);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,prevtime[i] + time[i]);
        }

        return ans;
    }
};
