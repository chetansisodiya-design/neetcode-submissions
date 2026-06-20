#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build Adjacency List: [Prerequisite] -> [Course]
        // The problem says [a, b] means b must be taken before a.
        // So the edge is b -> a.
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        // 0: Unvisited, 1: Visiting (Path), 2: Safe (Visited)
        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) return false; 
            }
        }
        return true;
    }

private:
    bool hasCycle(int curr, const vector<vector<int>>& adj, vector<int>& state) {
        state[curr] = 1; // Entering recursion stack

        for (int neighbor : adj[curr]) {
            if (state[neighbor] == 1) return true; // Cycle detected
            if (state[neighbor] == 0) {
                if (hasCycle(neighbor, adj, state)) return true;
            }
        }

        state[curr] = 2; // Finished exploring this node and its children
        return false;
    }
};
