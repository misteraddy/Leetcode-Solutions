class Solution {
public:

    unordered_map<string,int> dp;

    int maxLength(vector<string>& arr) {

        string temp = ""; //abhi tak koi concatenation nhi hua hai .

        dp.clear();  //har baar jab shuru hoga toh dp clear ho jayegaa
        
        int n = arr.size();

        return solveMaxLength(arr,0,n,temp); 
    }

    int solveMaxLength(vector<string>& arr,int i,int n,string temp)
    {
        if(i >= n)
        {
            return 0 ;
        }

        if(dp.find(temp) != dp.end())
        {
            return dp[temp];
        }

        int exclude = 0 ;

        int include = 0 ;

        int ans = 0 ;

        if(isValid(arr[i],temp))
        {
            exclude = 0 + solveMaxLength(arr,i + 1,n,temp);
        }
        else
        {                                                           //concatenated
            include = arr[i].length() + solveMaxLength(arr,i + 1,n,temp + arr[i]);

            exclude = 0 + solveMaxLength(arr,i + 1,n,temp); 
        }

        ans = max(include,exclude);

        return ans;
    }

    bool isValid(string& s1,string& s2)
    {
        int hash[26] = {0};

        for(auto i : s1)
        {
            if(hash[i - 'a'] > 0)
            {
                return true;
            }
            hash[i - 'a']++;
        }


        for(auto j : s2)
        {
            if(hash[j - 'a'] > 0)
            {
                return true;
            }
        }

        return false;
    }
};