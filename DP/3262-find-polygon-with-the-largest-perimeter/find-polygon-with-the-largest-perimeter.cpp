//THOUGHT PROCESS
/*

ek ek karke saare ka sum leta jaunga 

lekin current edge apne piche edges se chota bhi ho sakta

but sorting karne pe ye situation nhi aayegi 

the current edge hamesha badi hogi 

*/


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        //sort karenge kyunki normal traverse karne pe current edge condition ko satisfy 
        //kar sakte hai but actually voh shayad chota ho pichle element se 
        sort(nums.begin(),nums.end());

        long long perimeter = 0 ;

        long long remainingEdges = 0 ;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int longest = nums[i];

            //size 3 se bada ho 
            if(i > 1 && longest < remainingEdges) // the condition given in the question
            {
                perimeter = remainingEdges + nums[i]; //usko consider kar lenge agar aage 
                //ko bada edge nhi milta hai toh isko hi return kar denge
            }

            remainingEdges += nums[i]; //aur bada polygon exist kar sakta hai usko check 
            //karne hetu
        }


        return perimeter == 0 ? (-1) : perimeter ;
    }
};

//error
/*

Line 34: Char 44: runtime error: signed integer overflow: 1838609631 + 311935527 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:43:44

*/