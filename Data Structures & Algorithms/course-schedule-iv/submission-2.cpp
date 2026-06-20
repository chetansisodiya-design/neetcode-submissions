class Solution {
public:
    unordered_map<int, unordered_set<int>> prereqMap;
    vector<vector<int>> adj;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, vector<int>());
        // [0,1] = 1 course depent on course 0.
        // i want to create adj such that - node which dont depent on any course 
        // should come in the last in graph. So course should point ot depend on course.
        // means 1 --> 0
        for(auto preq: prerequisites){
            int cource = preq[1];
            int dependOn = preq[0];
            adj[cource].push_back(dependOn); 
        }

        ///loop over all node and call DFS
        for(int i = 0; i< numCourses; i++) {
            dfs(i);
        }

        // prereqMap contain course as key and values as prerequisite
        // [u,v] = true is u is pre-requisite of v ?
        // means true is for v as key, u present in value (means in set)
        vector<bool> result;
        for(auto query: queries) {
            // key =  v = query[1] , 
            // value(set) = preMap[query[1]]
            // search u (query[0] in set now using count function)
            result.push_back(prereqMap[query[1]].count(query[0]));
        }
        return result;
    }

    unordered_set<int>& dfs(int currNode) {
        if(prereqMap.count(currNode)) {
            return prereqMap[currNode];
        }     

        // loop over
        // assumption: DFS on neighbour will return all the nodes inset which are 
        // pre-requisite of course = currNode
        for(auto nei: adj[currNode]) {
            auto& preReqSet = dfs(nei);
            prereqMap[currNode].insert(preReqSet.begin(), preReqSet.end());
        }

        // currNode is pre-requisite of one node above. So add it in the set as well
        prereqMap[currNode].insert(currNode);
        return prereqMap[currNode];
    }
};