class Solution {
    // 1. The value of K can be 1 to maximum value of piles. So let left = 1 and right = max_val 
    // 2. Check for that k is possible or not. 
    // 3. If possible try for smaller value , if not try for larger values
public:
    long long int solve(vector<int>& piles, int k){
        long long int ans = 0;
        for(int i = 0; i < piles.size(); i ++){
            ans += ((piles[i] - 1) / k  + 1);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        while(left <= right){
            int mid = left + (right - left) / 2; // To control overflow
            if(solve(piles, mid) <= h){
                right = mid -1 ;
            }
            else left = mid + 1;
        }
        return left;
        
    }
};