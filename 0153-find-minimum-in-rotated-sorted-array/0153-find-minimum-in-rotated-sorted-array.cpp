class Solution {
public:
    // 1. The first element of the nums array is the maximum element of the 2 nd half.
    
    int findMin(vector<int>& nums) {

        int left = 0, right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] < nums[right] ) right = mid;
            else left = mid + 1;
        }
        return nums[left];
    }
};