class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i ++) mp[nums[i]] = i;

        for(int i = 0; i < nums.size(); i ++){
            int x = target - nums[i] ;
            if(mp.find(x) != mp.end() && i != mp[x]) {
                ans.push_back(i);
                ans.push_back(mp[x]);
                break;
            }
        }
        return ans;
        
    }
};
