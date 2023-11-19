class Solution {
public:
    // Function to find the previous smaller elements for each element in the input vector.
    // Time complexity: O(N), where N is the size of the input vector.
    // Space complexity: O(N), for the stack and output vector.
    vector<int> prevSmallerElements(vector<int>& heights) {
        int size = heights.size();
        vector<int> ans(size);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < size; i++) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Function to find the next smaller elements for each element in the input vector.
    // Time complexity: O(N), where N is the size of the input vector.
    // Space complexity: O(N), for the stack and output vector.
    vector<int> nextSmallerElements(vector<int>& heights) {
        int size = heights.size();
        vector<int> ans(size);
        stack<int> st;
        st.push(-1);

        for(int i = size - 1; i >= 0; i--) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Function to find the largest rectangle area formed by the input vector of heights.
    // Time complexity: O(N), where N is the size of the input vector.
    // Space complexity: O(N), for the output vector and auxiliary vectors used in nextSmallerElements and prevSmallerElements.
    int largestRectangleArea(vector<int>& heights) {
        vector<int> areaArr(heights.size());

        // Find the next smaller elements for each element in the input vector.
        vector<int> next = nextSmallerElements(heights);
        for(int i = 0; i < heights.size(); i++) {
            if(next[i] == -1) {
                next[i] = heights.size();
            }
        }

        // Find the previous smaller elements for each element in the input vector.
        vector<int> prev = prevSmallerElements(heights);

        // Calculate the area for each element and store it in the areaArr vector.
        for(int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            int width = next[i] - prev[i] - 1 ;
            int area = length * width;
            areaArr[i] = area;
        }

        // Find the maximum area in the areaArr vector.

        //The max_element function returns an iterator pointing to the maximum element in the range [first, last).
        //The * (dereference operator) is used to obtain the actual value pointed to by the iterator.
        int maxElement = *max_element(areaArr.begin(), areaArr.end());

        return maxElement;
    }
};
