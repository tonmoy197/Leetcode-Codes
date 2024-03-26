class Solution {
public:
    bool solve(unordered_set<string> &dict, string s, int start, vector<int> &dp){
        int n = s.size();
        if(start == n) return true;

        if(dp[start] != -1 ) return dp[start];
            
        for(int i = start; i < n; i ++){
            string temp = s.substr(start, i + 1 - start );
            if(dict.count(temp) && solve(dict, s, i + 1, dp )){
                dp[start] = true;
                return true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() , -1);
        return solve(dict, s, 0, dp);
        
        
    }
};