class Solution {
public:

    int solve(vector<int>& nums, vector<int>& dp, int i){
        // base case 
        if(i >= nums.size() ) return 0;
        
        if(dp[i] == -1){
            // taking current element and 2 next element , and taking next element
            dp[i] = max( solve(nums, dp, i + 1), nums[i] + solve(nums, dp, i + 2));
        }

        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);

        return solve(nums, dp, 0);
    }

};