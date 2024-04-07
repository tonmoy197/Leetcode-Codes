class Solution {
public:
//1. Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container.
// 2. Fix the higher one and flow water from the lower part.
// 3. For example, if current height of left is lower, we fill water in the left bin. Until left meets right, we filled the whole container.

    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int ans = 0;
        while(left <= right ){
            if(height[left] < height[right]){
                if(height[left] > maxLeft) maxLeft = height[left];
                else ans += maxLeft - height[left];
                left ++;
            }
            else {
                if(height[right] > maxRight) maxRight = height[right];
                else ans += maxRight - height[right];
                right --;
            }
        }
        return ans;
    }
};