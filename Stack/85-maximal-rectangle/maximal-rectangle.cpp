class Solution {
public:
    // Function to find the next smaller element's index for each element in the array
    vector<int> nextSmaller(vector<int>& arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            // Pop elements from the stack until a smaller element is found
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            // If the stack is empty, assign n to ans[i]; otherwise, assign st.top()
            ans[i] = (st.top() == -1) ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    // Function to find the previous smaller element's index for each element in the array
    vector<int> prevSmaller(vector<int>& arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            // Pop elements from the stack until a smaller element is found
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            // Assign st.top() to ans[i] if the stack is not empty; otherwise, assign -1
            ans[i] = (st.top() == -1) ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        if (n == 1) return heights[0];

        // Find the indices of the previous and next smaller elements
        vector<int> leftToRight = prevSmaller(heights, n);
        vector<int> rightToLeft = nextSmaller(heights, n);

        vector<int> area(leftToRight.size());

        // Calculate the area for each bar in the histogram
        for (int i = 0; i < leftToRight.size(); i++) {
            int width = rightToLeft[i] - leftToRight[i] - 1;
            int length = heights[i];
            area[i] = width * length;
        }

        // Find the maximum area in the histogram
        int maxi = INT_MIN;
        for (int i = 0; i < area.size(); i++) {
            maxi = max(maxi, area[i]);
        }

        return maxi;
    }

    // Function to find the maximal rectangle area in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int> heightOfCol(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++) {
            // Create a histogram for each row in the matrix
            for (int j = 0; j < heightOfCol.size(); j++) {
                if (matrix[i][j] == '1') {
                    heightOfCol[j]++;
                } else {
                    heightOfCol[j] = 0;
                }
            }

            // Update the maximum area considering the current histogram
            maxi = max(maxi, largestRectangleArea(heightOfCol));
        }

        return maxi;
    }
};
