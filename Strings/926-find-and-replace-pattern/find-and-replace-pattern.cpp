class Solution {
public:
    
    void createMapping(string& str)
    {
        char start = 'a'; // starting with a character you can start with any character 
        char mapping[300] = {0} ; // creating an character array of size more than 256 so that it can cover all the characters of the ascii table.
        
        // initalising all with 0
        
        for(auto ch : str)
        {
            if(mapping[ch] == 0)
            {
                mapping[ch] = start ; // placing the value of start where the index same to ascii value of the character
                start ++ ;  // updating the start
            } 
        }
        
        //update the string 
        
        for(int i = 0 ; i < str.length() ; i++)
        {
            char ch = str[i];
            str[i] = mapping[ch];
        }
        
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector <string> ans ;
        
        createMapping(pattern);
        
        for(string s : words)
        {
            string translate = s ;
            
            createMapping(translate);
            
            //both are translate to same format 
            //if the arrangement is same then push it into answer.
            if(translate == pattern)
            {
                ans.push_back(s);
            }
        }
        
        return ans ;
        
    }
};