class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            // If current number is closer to 0, update answer
            if(abs(nums[i])<abs(ans))
                ans=nums[i];
                // If both numbers are equally close to 0,
            // choose the larger value
            else if(abs(nums[i])==abs(ans) && nums[i]>ans)
                ans=nums[i];
        }
        return ans;
    }
};