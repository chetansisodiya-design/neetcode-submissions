class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxLen = 0;
       int maxFrequency = 0;
        unordered_map<char, int> H;
       int l = 0;
       for(int r = 0; r < s.size(); r++) {
        H[s[r]]++;
        maxFrequency =  max(maxFrequency, H[s[r]]);

        // lenth - maxFreq <= k (valid window)
        // length - maxFreq > k (invalid window)
        while(((r-l+1) - maxFrequency) > k) {
            // reduce window
            H[s[l]]--;
            // We should update maxFreq here Reason at the last
            //maxFrequency = max(maxFrequency, H[s[l]]);
            l++;
        }
        // valid window
        maxLen = max(maxLen, (r-l+1));
       } 
       return maxLen;
    }
};

/*
Imagine K=1 and the string is AAABBB.

Right moves to index 2: Window is AAA. maxFreq = 3. len = 3.

Right moves to index 3: Window is AAAB. (4 - 3) <= 1 is True. len = 4.

Right moves to index 4: Window is AAABB. (5 - 3) > 1 is False.

We shrink: l moves to 1. Window is AABB.

Crucial moment: The real maxFreq of AABB is 2. But we leave our variable at 3.

Wait! If we leave it at 3, our (r - l + 1) - 3 check is "fake."

But to get a window of length 5, we would eventually need a maxFrequency of 4 to pass the test (5 - 4) <= 1.

The moment we find 4 of the same character, our maxFrequency variable will update from 3 to 4 naturally.
*/
