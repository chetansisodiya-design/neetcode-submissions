class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(int i = 0; i< edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_set<int> visited;

        if(hasCycle(0,-1, adj, visited)) {
            return false;
        }
        return visited.size() == n;
    }

    bool hasCycle(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {

            visited.insert(node);

            for(int neighbor: adj[node]) {
                if(!visited.count(neighbor)) {
                    if(hasCycle(neighbor, node, adj, visited)) {
                        return true;
                    }
                } else if(parent != neighbor) {
                    return true;
                }
            }
            return false;
        }
};

