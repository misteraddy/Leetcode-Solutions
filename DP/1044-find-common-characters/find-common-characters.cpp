class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> v(26, INT_MAX); // to store the min frequency of each character
        vector<string> ans;

        for(int i = 0; i < n; i++) {
            vector<int> v1(26, 0); // to count frequency of each character in the current word
            for(int j = 0; j < words[i].size(); j++) {
                v1[words[i][j] - 'a']++;
            }
            for(int k = 0; k < 26; k++) {
                v[k] = min(v[k], v1[k]); // update the min frequency
            }
        }

        for(int i = 0; i < 26; i++) {
            while(v[i] > 0) { // while there's at least one occurrence of the character
                ans.push_back(string(1, 'a' + i)); // convert character to string and add to ans
                v[i]--;
            }
        }

        return ans;
    }
};
