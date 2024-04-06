class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() -  1;
        int ans = 0;
        while(left < right ){
            int lx = height[left];
            int rx = height[right];
            int diff = min(lx, rx);
            ans = max(ans, (right - left)*diff);
            if(lx < rx) left ++;
            else right --;
            
        }
        return ans;


    }
};