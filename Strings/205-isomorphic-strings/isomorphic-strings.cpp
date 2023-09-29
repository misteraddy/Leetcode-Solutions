class Solution {
public:
    
    string transform(string str)
    {
        char start = 'a';
        char mapping[300] = {0};
        
        for(int i = 0 ; i < str.size() ; i++ )
        {
            char ch = str[i];
            if(mapping[ch] == 0)
            {
                mapping[ch] = start ;
                start ++ ;
            }
        }
        
       for(int i = 0 ; i < str.size() ; i++)
       {
           char ch = str[i];
           str[i] = mapping[ch];
       }
        
        return str ;
    }
    
    bool isIsomorphic(string s, string t) {
        
        string transformed_s = transform(s);
        
        string transformed_t = transform(t);
        
        int result = transformed_s.compare(transformed_t);
        
        if(result)
        {
            return false ;
        }
        else
        {
            return true ;
        }
    }
};