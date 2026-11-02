
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());

        int sum = 0;

        // Step 2: Add elements at even indices
        for(int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};
