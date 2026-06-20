class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // run a dfs on all vertex. 
        // ignore visited node.
        // increase counter everytime 
        vector<int> visited(n,0);
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int counter{0};
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited);
                counter++;
            }
        }
        return counter;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        for(int nei: graph[node]) {
            if(!visited[nei])
                dfs(nei, graph, visited);
        }
    }
};
