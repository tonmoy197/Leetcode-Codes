class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // checking from left side and the right side
        int n = nums.size();
        int left = 1, right = 1, res = nums[0];
        for(int i = 0; i < n; i ++){
            
            // left side 
            if(left == 0) left = 1;
            left *= nums[i];
            
            // right side
            if(right == 0) right = 1; 
            right *= nums[n - i -1];
            
            // finding result
            res = max(res, max(left, right ));
        }
        
        return res;
        
    }
};