class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //vector<int> orderIndex(26);
        int orderIndex[26];
        for(int i = 0 ;i< order.size(); i++) {
            orderIndex[order[i]-'a'] = i;
        } 

    auto compare = [&](const string& a, const string& b) {
            // if both string match then return true is a< b else false
            // if character dont match then return true of char a is lenn than char of b
            for(int i = 0; i< min(a.size(), b.size()); i++) {
                if(a[i] != b[i]) {
                    return orderIndex[a[i]-'a'] < orderIndex[b[i]-'a'];
                }
            }
                // reached here means one string full match the other. 
                // so return based on size. 
            return a.size() < b.size();

        };
        return is_sorted(words.begin(), words.end(), compare);
    }
};