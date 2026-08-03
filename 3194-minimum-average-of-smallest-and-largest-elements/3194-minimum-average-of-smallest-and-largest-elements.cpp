class Solution {
public:
    double minimumAverage(vector<int>& nums) {
         // Sort the array
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        double minAvg=1e9;
        // Pair the smallest and largest elements
        while(left<right){
            double avg=(nums[left]+nums[right])/2.0;
            if (avg<minAvg)
                minAvg=avg;
            left++;
            right--;
        }
        return minAvg;
    }
};