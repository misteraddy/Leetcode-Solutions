class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = needle.size() - 1;

        int size = haystack.size();

        int index = -1;

        while (j < size) {
            // Create a temporary substring from haystack of the same length as needle
            string temp = haystack.substr(i, needle.size());

            if (temp == needle) {
                index = i;
                break; // Exit the loop if a match is found
            }

            i++;
            j++;
        }

        return index;
    }
};
