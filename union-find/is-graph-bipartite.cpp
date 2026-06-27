class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, 0);
        queue<int> q;
        q.push(0);
        color[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto itr : graph[node]) {
                if(color[itr] == 0) {
                    if(color[node] == 1) {
                        color[itr] = 2;
                        q.push(itr);
                    } else if(color[node] == 2) {
                        color[itr] = 1;
                        q.push(itr);
                    }
                } else if(color[itr] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
};