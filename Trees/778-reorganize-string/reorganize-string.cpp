class Info {
public:
    char val;
    int count;

    Info(char val, int count) : val(val), count(count) {}
};

 //kyunki hum log dynamic memory nhi use kar rahe hai thats why we are using INFO not INFO*
//pointer agar ye hote then a-> val

class compare {
public:
    bool operator()(Info a, Info b) {
        return a.count < b.count;
    }
};

/*

This code defines a custom comparator class named compare that overloads the () operator. 

*/

class Solution {
public:
    std::string reorganizeString(std::string s) {
        std::string ans = "";
        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        std::priority_queue<Info, std::vector<Info>, compare> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                Info temp(i + 'a', freq[i]);
                pq.push(temp);
            }
        }

        while (pq.size() > 1) {
            Info first = pq.top();
            pq.pop();
            ans.push_back(first.val);
            first.count--;

            Info second = pq.top();
            pq.pop();
            ans.push_back(second.val);
            second.count--;

            if (first.count != 0) {
                pq.push(first);
            }

            if (second.count != 0) {
                pq.push(second);
            }
        }

        while (!pq.empty()) {
            Info first = pq.top();
            pq.pop();

            ans.push_back(first.val);

            first.count--;

            if (first.count != 0) {
                return "";
            }
        }

        return ans;
    }
};

// APPROACH
/*
   The approach uses a priority queue to rearrange characters in the input string. 
   It begins by calculating the frequency of each character in the input string.
   Then, it creates Info objects with the character and its frequency, pushing them into a priority queue based on frequency.
   The program repeatedly extracts two Info objects with the highest frequency, appends their characters to the result string, and decrements their counts.
   The process continues until there is only one element in the priority queue. In the end, it checks for any remaining character with non-zero count.
   If found, the string cannot be rearranged, and an empty string is returned; otherwise, the rearranged string is returned.
*/

// THINGS YOU LEARNED
/*
   - Using a priority queue (max heap) to efficiently handle characters with the highest frequency.
   - Creating a custom comparator for Info objects to prioritize higher frequencies.
   - Checking and handling corner cases when dealing with the priority queue and character counts.
*/

// CORNER CASES
/*
   - The code handles cases where characters need to be rearranged to form a valid string.
   - Checks for situations where it is not possible to rearrange the string, returning an empty string in such cases.
   - Handles scenarios where the input string is empty or has only one character.
*/

// TIME COMPLEXITY - O(N log N)
/*
   - The time complexity is dominated by the operations involving the priority queue.
   - Constructing the priority queue takes O(N log N) time, where N is the size of the input string.
   - The extraction and insertion operations in the priority queue are repeated until there is only one element left.
*/

// SPACE COMPLEXITY - O(N)
/*
   - The space complexity is determined by the storage of Info objects in the priority queue.
   - In the worst case, the priority queue can store all distinct characters with their frequencies.
   - Thus, the space complexity is O(N), where N is the number of distinct characters in the input string.
*/
