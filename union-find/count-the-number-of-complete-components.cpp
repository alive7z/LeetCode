class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int& cntNodes, int& cntEdges) {
        cntNodes += 1;
        cntEdges += adj[node].size();
        visited[node] = true;
        for(auto itr : adj[node]) {
            if(!visited[itr]) {
                dfs(adj, visited, itr, cntNodes, cntEdges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto itr : edges) {
            int u = itr[0];
            int v = itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int cntNodes = 0, cntEdges = 0;
                dfs(adj, visited, i, cntNodes, cntEdges);
                cntEdges /= 2;
                if(cntEdges == cntNodes * (cntNodes - 1) / 2) ans++;
            }
        }

        return ans;
    }
};