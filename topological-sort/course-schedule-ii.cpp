class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto itr : prerequisites) {
            int u = itr[0];
            int v = itr[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto itr : adj[node]) {
                inDegree[itr]--;
                if(inDegree[itr] == 0) q.push(itr);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};