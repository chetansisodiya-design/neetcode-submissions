
class Solution {
public:
    class MyCompare {
        public:
        bool operator() (const pair<int, int>& a, const pair<int, int>&b) {
            return a.second < b.second;
        }
    };    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> H;

        for(auto c: nums) {
            H[c]++;
        }
        priority_queue<pair<int, int> ,vector<pair<int, int>>, MyCompare> PQ;
        //priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> PQ;
        for(const auto pair: H) {
            PQ.push(pair);
        }
        
        vector<int> result;
        int count = 1;
        while(!PQ.empty() && count <= k) {
            result.push_back(PQ.top().first);
            PQ.pop();
            count++;
        }
        return result;
    }

};
