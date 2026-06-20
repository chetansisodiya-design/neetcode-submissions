class Solution {
public:

    string encode(vector<string>& strs) {
        string op;
        for(auto str: strs) {
            int size = str.size();
            //op += to_string(str.size()) + "#" + str;
            
            op += to_string(str.size()); 
            op += "#";
            op += str; 
        }
        return op;
    }

    vector<string> decode(string s) {
        vector<string> op;
        int i = 0;
        while (i < s.size()) {
            // search #
            int j = i;

            while(s[j] != '#') {
                j++;
            }
        
            // len = j-i+1 (len between j & i)
            // j abhi # per hai tp hame usko ignore karna hia
            int len = stoi(s.substr(i, j-i));

            // string len = len
            string str = s.substr(j+1, len);
            
            op.push_back(str);

            i = j+1+len;
        }
        return op;
    } 
    
};
