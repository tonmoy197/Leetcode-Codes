class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        
        for(int i = 0; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++){
                int k = j + 1;
                int l = n - 1;
            
                while(k < l){
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(target == sum){
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k ++;
                        l --;
                    }
                    else if (sum < target) k ++;
                    else l -- ;
                }   

            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};