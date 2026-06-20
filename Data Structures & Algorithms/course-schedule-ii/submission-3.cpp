class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int dependency = edge[1];
            adj[course].push_back(dependency);
        }  
        // NodeState
        vector<int> nodeState(numCourses,0);
        // 0 Unvisited
        // 1 visitin (on Stack)
        // 2 No Cycle Present for this node (safe node)

        vector<int> courseOrder;
        courseOrder.reserve(numCourses); // Optimization: avoid reallocations

        for(int i =0; i< numCourses; i++) {
            // if a cycle is present its impossible to finishe  courses
            if(hasCycle(i, adj, nodeState, courseOrder)) {
                return {};
            }
        }
        return courseOrder;

    }

    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& nodeState, vector<int>& courseOrder)
    {
        if(nodeState[node] == 1) return true;
        if(nodeState[node] == 2) return false;

        nodeState[node] = 1;
        for(auto neighbor: adj[node]) {
            if(hasCycle(neighbor, adj, nodeState, courseOrder)) {
                return true;
            }
        }
        // reached here means node has not cycle.. So mark is safe
        nodeState[node] = 2;
        // reached here means all the prerequisite for thie course node are completed
        // So we can add node course now    
        courseOrder.push_back(node);
        //obviously there is not cycle for current node (node)
        return false;
    }
};
