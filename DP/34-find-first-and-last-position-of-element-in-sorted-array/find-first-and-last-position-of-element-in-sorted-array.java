class Solution {
    public int binarySearch(int[] nums, int target, boolean findFirst) {
        int s = 0;
        int e = nums.length - 1;
        int index = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                index = mid;
                if (findFirst)
                    e = mid - 1; // Find first occurrence
                else
                    s = mid + 1; // Find last occurrence
            } else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return index;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] range = new int[2];
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        range[0] = first;
        range[1] = last;
        return range;
    }
}