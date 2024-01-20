class Solution {
public:

    vector<int> getNSL(vector<int>& arr,int n)
    {
        stack<int> st ;

        vector<int> ans(n) ;

        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(st.empty())
            {
                ans[i] = (-1);
            }
            else
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }

                ans[i] = st.empty() ? (-1) : st.top();

            }

            st.push(i);
        }

        return ans;
    }

    //there will be a corner case when duplicate elements are present toh usko handle karne k liye 
    //dono mei se kisi ek mei duplicate element ko include karenge malab equal to ko laga do

    vector<int> getNSR(vector<int>& arr,int n)
    {
       stack<int> st ;

        vector<int> ans(n) ;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(st.empty())
            {
                ans[i] = (n);
            }
            else
            {
                while(!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }

                ans[i] = st.empty() ? (n) : st.top();  
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        
        vector<int> NSL = getNSL(arr,n);

        vector<int> NSR = getNSR(arr,n);

        int mod = 1e9 + 7 ;

        long long sum =  0 ;

        for(int i = 0 ; i < arr.size() ; i++)
        {
            long long ls = i - NSL[i];

            long long rs = NSR[i] - i;

            long long totalways = ls*rs ;

            long long subarraySum = arr[i]*totalways ;

            sum = (sum + subarraySum)% mod ;
        }

        return sum ;
    }
};