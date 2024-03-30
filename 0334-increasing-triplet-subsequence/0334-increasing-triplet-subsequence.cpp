class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++){
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            if(it == ans.end()) ans.push_back(nums[i]);
            else *it = nums[i];
        }

        if(ans.size() >= 3 ) return true;
        else return false;
    }
};