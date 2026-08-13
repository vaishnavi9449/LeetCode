class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot exists, this is the largest permutation
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element greater than nums[pivot]
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the part after pivot
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};