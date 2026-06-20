class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        // do BFS. 
        queue<string> q;
        unordered_set<string> visit(deadends.begin(), deadends.end());

        if(visit.count("0000")) return -1;

        q.push("0000");
        visit.insert("0000");
        int turns = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i =0;i< size;i++) {
                //pop frp queue
                string lock = q.front();
                q.pop();

                if(lock == target) return turns;

                // loop over 8 combination
                for(string child: computeChild(lock)) {
                    // ye allowed lock hoga ot aage jayenge
                    if(!visit.count(child)) {
                        visit.insert(child);
                        q.push(child);
                    }
                }
            }
            turns++; // Increment once per "layer" of the search

        }
        // target not mateched.. Else pahle hi return kar dete.. So return -1
        return -1;
    }

    vector<string> computeChild(string target) {
        vector<string> res;
        for(int i =0; i< target.size(); i++) {
            // do plus one first
            string next = target;
            next[i] = (next[i]-'0'+1)%10+'0';
            res.push_back(next);

            // do minus 1 no
            next = target;
            next[i] = (next[i]-'0'-1+10)%10+'0';
            res.push_back(next);
        }
        return res;
    }
};