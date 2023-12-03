//ERROR THAT I WAS DOING IN THIS QUESTION
//isme bas small letters hi aayenge toh 255 dont take
//


class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        int ans = -1;

        // Use vector size 26 for lowercase or uppercase letters
        //mai yaha par vector ko 255 size ka bana rha tha
        //i think vector mei pehle se hi saare indexes 0 se initialised hote hai
        //hash(26, 0) toh ye karne ka koi faydaa nhi hai
        vector<int> hash(26, 0);
        queue<int> q;

        for (int i = 0; i < size; i++) {
            int val = s[i] - 'a';  // Use 'a' for lowercase, 'A' for uppercase
            hash[val]++;
            q.push(i);
        }

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            int val = s[index] - 'a';  // Use 'a' for lowercase, 'A' for uppercase

            if (hash[val] == 1) {
                ans = index;
                break;
            }
        }

        return ans;
    }
};