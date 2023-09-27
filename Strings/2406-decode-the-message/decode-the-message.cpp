class Solution {
public:
    string decodeMessage(string key, string message) {
        
        //the string is starting with the first character 
        char start = 'a' ;
        
//         you can take mapping character array of any size 256 se upar honi chahiye value 
        // isko hashing se bhi solve kar sakte 
        //ch mei joh bhi character hoga uski ascii value as a index treat hogi
        char mapping[300] = {0};
        
        
        // for each loop for traversing each char of key
        // val not gives the value it gives the index
        for(auto val : key)
        {
            char ch = val ;
            
            //condition is 
            //space nhi hona chahiye 
            //pehle se agar voh character mapped hai toh value overwrite nhi karenge
            //vohi ko use karenge
            if(ch != ' ' && mapping[ch] == 0)
            {
                mapping[ch] = start ;
                start ++ ;
            }
            
        }
        
        //using the key mapping 
        
        string ans ;
        //string for storing ans
        
        for(auto ch : message)
        {
            
            if(ch == ' ')
            {
                ans.push_back(' ');
            }
            else
            {
                //decoding the message by traversing entire string and for each character 
                // of the message we check whether mapping is present 
                // if mapping is present then we push it in the same place in the ans string
                char decoded_char = mapping[ch];
                ans.push_back(decoded_char);
            }
        }
        
        
        return ans ;
        
    }
};