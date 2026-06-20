
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
        // Min Heap
        priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        //priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> PQ;
        for(const auto& pair: H) {
            PQ.push({pair.second, pair.first});
            if(PQ.size() > k) {
                PQ.pop();
            }
        }
        
        vector<int> result;
        while(!PQ.empty()) {
            result.push_back(PQ.top().second);
            PQ.pop();
        }
        return result;
    }

};
