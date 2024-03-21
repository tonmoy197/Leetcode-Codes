class Solution {
public:
    int solve(vector<int> &cost, vector<int> &dp, int i){
        int n = cost.size();
        if( i == n - 1 || i == n - 2 ) return cost[i];
        if(dp[i] == -1 ){
            dp[i] = cost[i] + min( solve(cost, dp, i + 1) , solve(cost, dp, i + 2));
        }
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int s1 = solve(cost, dp, 0);
        int s2 = solve(cost, dp, 1);
        return min(s1, s2);
    }
};