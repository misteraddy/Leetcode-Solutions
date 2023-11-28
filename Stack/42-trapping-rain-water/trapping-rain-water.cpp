#include <vector>
#include <stack>

class Solution {
public:
    int trap(const vector<int>& height) {
    stack<int> heightStack;  // Stack to store indices of heights
    int totalWater = 0;

    // Iterate through each element in the height array
    for (int i = 0; i < height.size(); ++i) {
        // While the stack is not empty and the current height is greater than the height at the top of the stack
        while (!heightStack.empty() && height[i] > height[heightStack.top()]) {
            int poppedIndex = heightStack.top();
            heightStack.pop();

            // If the stack becomes empty, break out of the loop
            if (heightStack.empty()) {
                break;
            }

            // Calculate the distance between the current element and the element at the top of the stack
            int distance = i - heightStack.top() - 1;
            // Calculate the height difference between the popped element and the current element
            int minHeight = min(height[i], height[heightStack.top()]) - height[poppedIndex];
            // Add the trapped water (distance * height difference) to the total trapped water
            totalWater += distance * minHeight;
        }

        // Push the current element's index onto the stack
        heightStack.push(i);
    }

    // Return the total trapped water
    return totalWater;
}
};
