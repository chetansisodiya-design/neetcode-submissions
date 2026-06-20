class Solution {
public:

    string encode(vector<string>& strs) {
        string op;

        for(string str: strs) {
            op += to_string(str.size());
            op += '#';
            op += str;
            //op.push_back(str); ye kaam nahi karega.. push_back is for single char
            // OR 
            // op += stoi(str.size()) + "#" + str; 
        }
        return op;
    }

    vector<string> decode(string s) {
        // 6#chetan8#sisodiya
        vector<string> op;
        int i = 0;
        while(i < s.size()) {
            int j = i ;
            while(s[j] != '#') {
                j++;
            }
            // len = j-i+1 (len between j & i)
            // j abhi # per hai tp hame usko ignore karna hia
            //int len = stoi(s.substr(i, j-i));
            int len = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, len);
            
            op.push_back(str);
            i = j + 1 + len;
            /// j+1 to cross #, +len to cross the string
        }
        return op;
    }
};
