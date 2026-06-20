#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numCourses, false);  // To skip safe branches
        vector<bool> currPath(numCourses, false); // To detect cycles

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(i, adj, visited, currPath)) return false;
            }
        }
        return true;
    }

private:
    bool hasCycle(int curr, const vector<vector<int>>& adj, 
                  vector<bool>& visited, vector<bool>& currPath) {
        
        visited[curr] = true;
        currPath[curr] = true; // Mark node in current path

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, adj, visited, currPath)) return true;
            } else if (currPath[neighbor]) {
                return true; // Cycle detected: neighbor is in current stack
            }
        }

        currPath[curr] = false; // Backtrack: remove from current path
        return false;
    }
};