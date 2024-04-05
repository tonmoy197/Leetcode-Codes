class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        // count number of zeros
        int cnt0 = 0;
        for(auto u : nums ) if(u == 0)  cnt0 ++;

        // if it has one zero 
        int ans = 1;
        if(cnt0 == 1 ){
            for(auto u : nums ) if(u != 0)  ans *= u;
            for(int i = 0; i < nums.size(); i ++){
                if(nums[i] == 0) answer[i] = ans;
                else answer[i] = 0;
            }
            return answer;
        }

        // when count is greater than one zero
        else if (cnt0 > 1){
            return answer;
        }
        // when there is no zero 
        else{
            int total = 1;
            for(auto u : nums) total *= u;
            for(int i = 0; i < nums.size(); i ++){
                answer[i] = total/ nums[i];
            }
            return answer;
        }

    }
};