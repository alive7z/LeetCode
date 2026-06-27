class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(color[i] > 0) continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto itr : graph[node]) {
                    if(color[itr] == -1) {
                        color[itr] = !color[node];
                        q.push(itr);
                    } else if(color[itr] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};