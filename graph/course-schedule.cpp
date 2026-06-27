class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto itr : prerequisites) {
            adj[v].push_back(u);
            inDegree[u]++;
        }
        vector<int> queue;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!queue.empty()) {
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