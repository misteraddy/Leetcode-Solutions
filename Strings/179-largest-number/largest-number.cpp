class Solution {
public:
    
    // Custom comparison function for sorting strings
    static bool mycomp(string a , string b)
    {
        string t1 = a + b ;
        string t2 = b + a ;
        
        return t1 > t2; // Compare based on the first character of each string . This is also called the 0 index sorting. 
        
        // In the custom comparator function mycomp, when a[0] > b[0] evaluates to true, it means that the first character of string a is greater than the first character of string b.In this case, 'a' will be placed before 'b' in the sorted order.
        
        
    }
    
    // Function to find the largest number by concatenating elements of 'nums'
    string largestNumber(vector<int>& nums) {
        
        // Step 1: Convert integers in 'nums' to strings
        vector <string> snums ;
        for(auto n : nums)
        {
            snums.push_back(to_string(n)); //convert each integer to string using this
        }
        
        
        
                            
        // result example =>  snums = ["3","30","34","5","9"]
        
        // Step 2: Sort the strings in descending order using custom comparison function 'mycomp'
        sort(snums.begin(),snums.end(),mycomp);
        
        // Step 3: Concatenate sorted strings to form the result
        string ans = "" ;
        
        // a test [0,0] output -> "0" we have to explicitly handle it .
        //keep it below the ans .
        if(snums[0] =="0")
        {
            return "0" ;
        }
        
        
        for(int i = 0 ; i < snums.size() ; i++ )
        {
            ans += snums[i];
        }
        
        // Step 4: Return the largest number as a string
        return ans ;
    }
};
