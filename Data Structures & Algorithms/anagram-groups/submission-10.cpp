class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;

        for(const auto& word: strs) {
            string temp = word;
            sort(temp.begin(), temp.end());

            H[temp].push_back(word);
        }

        vector<vector<string>> result;
        /*
        for(auto &p: H) {
            result.push_back(p.second);
        }*/

        // Map H is about to go away so better to steal the vector rather then copy
        for(auto [key, group] : H) {
            result.push_back(std::move(group));
        }
        return result;
        /*
        Why these minor tweaks matter here:
std::move(group) is a massive win: In your original draft, result.push_back(p.second) forces the std::vector copy-constructor to fire for every single group of anagrams. Because map is about to fall out of scope and be destroyed anyway, std::move() allows result to just steal the internal heap pointers of those vectors in O(1) time.
result.reserve(map.size()): Because you inherently know the exact final size of the result container the moment the first loop finishes, reserving it prevents the vector from having to double its capacity and re-copy its contents 3 to 4 times as the map drains into it.
Structured bindings ([key, group]): Just saves you from having to look at the word .second, which makes the intent instantly more readable.
*/
    }
};
