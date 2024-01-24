class Solution {
public:

    class compare{
        public:
            bool operator()(vector<int>&a , vector<int>& b)
            {
                if(a[0] == b[0])
                {
                    return a[1] > b[1] ;  //decreasing order
                }

                return a[0] < b[0] ;
            }
    };

    int solveUsingBinarySearch(vector<vector<int>>& envelopes)
    {
        vector<int> ans ;

        ans.push_back(envelopes[0][1]);

        for(int j = 0 ; j < envelopes.size() ; j++ )
        {
            if(envelopes[j][1] > ans.back())
            {
                ans.push_back(envelopes[j][1]);
            }
            else
            {
               int index = lower_bound(ans.begin(),ans.end(),envelopes[j][1]) - ans.begin();
               ans[index] = envelopes[j][1];
            }
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),compare());

        int ans = solveUsingBinarySearch(envelopes);

        return ans;

    }
};