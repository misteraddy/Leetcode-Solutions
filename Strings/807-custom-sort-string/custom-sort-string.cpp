class Solution {
public:
    
    //custom comparator
        static string str ;
        
        static bool compare(char ch1 , char ch2)
        {
            //this will return true  , if position of characters1 in str string is 
            //less then the position of character2 in str string
            
            //when true is returned , then ch1 will be placed before ch2 in output string
            return (str.find(ch1) < str.find(ch2));
        }
    
    string customSortString(string order, string s) {
        
        str = order ;
        
        sort(s.begin(),s.end(),compare);
        
        return s ;
    
    }
};

string Solution :: str ;