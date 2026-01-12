class Solution {
    static int findFirst(const vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();

        while (begin < end) {
            int mid = (begin + end) / 2;

            if (nums[mid] == target && ((mid == begin) || (nums[mid-1] < target))) {
                return mid;
            }
            else if (nums[mid] >= target) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }

        return -1;
    }

    static int findLast(const vector<int>& nums, int begin, int target) {
        int end = nums.size();

        while (end > begin) {
            int mid = (begin + end) / 2;

            if (nums[mid] == target && ((mid+1 == end) || (nums[mid+1] > target))) {
                return mid;
            }
            else if (nums[mid] <= target) {
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return begin;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) {
            return {-1 , -1};
        }
        int last = findLast(nums, first, target);
        return {first, last};
    }
};
