class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i){

        // base case 
        if(nums.size() == 1) return nums[0];
        if(i >= nums.size() ) return 0;
    
        // recurence relation
        if(dp[i] == -1){
            dp[i] = max(nums[i] + solve(nums, dp, i + 2), solve(nums, dp, i + 1));
        }
        return dp[i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        vector<int> h1(nums.begin(), nums.end()-1);
        vector<int> h2(nums.begin() + 1, nums.end());

        return max(solve(h1, dp1, 0), solve(h2, dp2, 0));
        
    }
};