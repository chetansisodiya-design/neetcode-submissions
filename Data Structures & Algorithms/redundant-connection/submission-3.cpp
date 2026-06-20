class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        // Using DFS
        // For each edge check is we can traver from u to v.
        // if yes then cycle present. else cycle not prent. 
        int n = edges.size();
        vector<vector<int>> graph(n+1);

        for(const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n + 1, false);
            if(PathPresent(u, v, graph, visited)) {
                return edge;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

    bool PathPresent(int currNode, int targetNode, vector<vector<int>>& graph,vector<bool>& visited) {
        if(currNode == targetNode) {
            return true;
        }
        visited[currNode] = true;

        for(auto nei: graph[currNode]) {
            if(!visited[nei]) {
                if(PathPresent(nei, targetNode, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
