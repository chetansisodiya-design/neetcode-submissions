class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Use Disjoint Set Union (Union-Find) to track connected components while adding edges one by one.
        /*

    Initially, every node is its own component.
    When we add an edge (u, v):
        If u and v are already in the same component, adding this edge creates a cycle.
        That edge is exactly the redundant connection.
    If they are in different components, we safely merge them.

Because edges are processed in order, the first edge that fails to union is the answer.
        */
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1); // all have rank1

        // make a node its own parent
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
        }

        // loop over each edge
        for(const auto& edge: edges) {
            if(!Union(parent, rank, edge[0], edge[1])) {
                return vector<int> {edge[0], edge[1]};
            }
        }
        return {};
    }

    int findParent(vector<int>& parent, int node) {
        if(parent[node] == node) 
            return node;

        return parent[node] = findParent(parent, parent[node]);
        
    }

    bool Union(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = findParent(parent, n1);
        int p2 = findParent(parent, n2);

        if(p1 == p2) {
            // this edge is creating a cycle now
            return false;
        }

        // check rank now
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

};
