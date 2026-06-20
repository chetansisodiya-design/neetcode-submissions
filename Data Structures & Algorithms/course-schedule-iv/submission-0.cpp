class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // BFS Approach
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<unordered_set<int>>  preReq(numCourses);

        /// [a, b] == course= b, dependecy a
        for(auto& pre: prerequisites) {
            int course = pre[0];
            int dependency = pre[1];
            adj[course].push_back(dependency);   
            indegree[dependency]++;
        }

        queue<int> q;
        for(int i = 0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto neighbor: adj[node]) {
                indegree[neighbor]--;
                preReq[neighbor].insert(node);
                preReq[neighbor].insert(preReq[node].begin(), preReq[node].end());
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        vector<bool> results;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];
            // Check if u exists in the prerequisite set of v
            results.push_back(preReq[v].count(u));
        }
        return results;
    }
};