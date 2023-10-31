class Solution {
public:
    void merge(vector<int>& nums, int start, int end, int mid) {
        int total_size = end - start + 1;
        int gap = (total_size / 2) + (total_size % 2);

        while (gap > 0) {
            
            //agar i ka element bada hai j se toh swap kar denge iss tarah 
            //correct position pe swapping ho jayegi.
            
            // the (total_size / 2) + (total_size % 2) calculation ensures that the gap is rounded up to the nearest integer if total_size is odd.
            
            for (int i = start; i + gap <= end; i++) {
                int j = i + gap;
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
            
            //in case agar gap 1 se chota hua toh loop se bahar
            
            if (gap <= 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return; // Base case: array has 0 or 1 element, which is already sorted.
        }

        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, end, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
