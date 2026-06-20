class UnionFind {
    vector<int> parent;
    vector<int> rank;

    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n,1);

            for(int i=0; i< n; i++) {
                parent[i] = i;
            }
        }

        int findLeader(int node) {
            if(node == parent[node]) {
                return node;
            }

            parent[node] = findLeader(parent[node]);
            return parent[node];
        }

        bool unionSets(int n1, int n2) {
            int p1 = findLeader(n1);
            int p2 = findLeader(n2);

            if(p1 == p2) {
                return false;
            }

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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> emailToAccntMap;
        int accountCounter = 0;
        UnionFind UF(n);
        // Build union find structure
        for(int i =0; i< n; i++) {
            // accounts[i] is the vector of string. So loop over again
            for(int j = 1; j< accounts[i].size(); j++) {
                //if accounts[i][j] is present already in map then union else insert
                const string& email = accounts[i][j];
                if(emailToAccntMap.count(email)) {
                    UF.unionSets(i, emailToAccntMap[email]);
                } else {
                    emailToAccntMap[email] = i;
                    // I is the account number. 
                }
            }
        }
        // Now merge all the related email in same group based on acount Id
        map<int, vector<string>> emailGroup;

        for(const auto& [email, accntId] : emailToAccntMap) {
            int leader = UF.findLeader(accntId);
            emailGroup[leader].push_back(email);
        }

        // Build Result by browsing emailGroup
        vector<vector<string> > result;
        for(auto& [accntId, emails] : emailGroup) {
            // emails is vector of string. So sort that.
            sort(emails.begin(), emails.end());
            // fetch accnt name based on account id.
            const string& accntName = accounts[accntId][0];
            vector<string> merged;
            merged.push_back(accntName);
            merged.insert(merged.end(),emails.begin(), emails.end());
            result.push_back(merged);
        }
        return result;
    }
};