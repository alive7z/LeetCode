class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        for(auto itr : graph[node]) {
            if(color[itr] == -1) {
                color[itr] = !color[node];
                if(!dfs(graph, color, itr)) return false;
            } else if(color[itr] == color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!dfs(graph, color, i)) return false;
            }
        }
        return true;
    }
};