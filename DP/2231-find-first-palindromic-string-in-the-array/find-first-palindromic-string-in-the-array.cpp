class Solution {
public:
    // Function to check if a given string is a palindrome.
    bool check(string s)
    {
        int start=0;
        int end=s.length()-1;
        // Loop until the start index is less than the end index.
        while(start<end)
        {
            // If characters at start and end indices are not equal, return false.
            if(s[start]!=s[end])
                return false;
            // Move start index forward and end index backward.
            start++;
            end--;
        }
        // If loop completes without returning false, the string is a palindrome, so return true.
        return true;
    }
    
    // Function to find the first palindrome in a vector of strings.
    string firstPalindrome(vector<string>& words) 
    {
        // Iterate through the vector of strings.
        for(int i=0;i<words.size();i++)
        {
            // If the current string is a palindrome, return it.
            if(check(words[i]))
                return words[i];
        }
        // If no palindrome is found, return an empty string.
        return "";
    }
}; 
