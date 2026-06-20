class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //prerequisites[i] = [ai, bi] indicates
        // b to be taken first before a.
        // a --> b 
        //For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
        // 0 --> 1 ( 0 depent on 1)

        vector<vector<int>> adj(numCourses);
        for(int i = 0; i< prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int dependOn = prerequisites[i][1];
            adj[course].push_back(dependOn);
        }

        vector<int> state(numCourses, 0);
        vector<int> courses;
        for(int i = 0; i<numCourses; i++) {
            if(state[i] == 0) {
                if(hasCycle(i, adj, state, courses)) {
                    return {};
                }
            }
        }
        return courses;
    }
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& courses) {
        // mark visited
        state[node] = 1;

        for(int neighbor: adj[node]){
            // if not visited, visit then
            if(state[neighbor] == 0) {
                if(hasCycle(neighbor, adj, state, courses)) {
                    return true;
                }
            } else if (state[neighbor] == 1) {
                return true; // CYcle present
            }
        }
        // reached here means not cycle present.
        // Also Node (node) not pointing to any neighbor.. Means this can be picked now. (0-->1) means 0 depend on 1.. But node dont
        // neighbor so that can be added now to course list.
        courses.push_back(node);
        state[node] = 2; // mark it super safe
        return false;
    }
};