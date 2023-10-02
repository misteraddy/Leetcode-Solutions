class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        // if (strs.empty()) {
        //     return ans; // If the input vector is empty, return an empty string.
        // }

        for(int i = 0; i < strs[0].size(); i++) {
            char current_char = strs[0][i];
            
            // Check if the current character is common in all strings.
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != current_char) {
                    return ans; // If not common, return the prefix found so far.
                }
            }
            
            ans += current_char;
        }
        
        return ans;
    }
};
