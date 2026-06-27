class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto itr : adj[node]) {
                inDegree[itr]--;
                if(inDegree[itr] == 0) q.push(itr);
            }
        }
        return count == numCourses;
    }
};