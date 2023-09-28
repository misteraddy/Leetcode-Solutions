class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map to store anagrams as keys and the corresponding words as values
        // This map will help group anagrams together efficiently
        map<string, vector<string>> mp;
        
        // Loop through each string in the input vector
        for(auto ch : strs) {
            string s = ch;
            
            // Sort the characters in the string to make an anagram identifier
            sort(s.begin(), s.end());
            
            // Add the original string to the vector associated with the sorted string
            mp[s].push_back(ch);
        }
        
        // Create a vector to store the grouped anagrams
        //[["bat"],["nat","tan"],["ate","eat","tea"]] output is like this
        //so we have to return vector of vectors where the vectors in which the values of the           same keys are grouped together 
        vector<vector<string>> ans;
        
        // Iterate through the map and add each group of anagrams to the answer vector
        
        //second is used to access the value part of that pair.
        
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
            
        }
        
        // Return the final vector of grouped anagrams
        return ans;
    }
};
