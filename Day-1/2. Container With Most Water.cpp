// Link - https://leetcode.com/problems/container-with-most-water/
// Author - Shumbul Arifa

class Solution {
public:
    int maxArea(vector<int>& height) {
        int x, y, maxarea=INT_MIN;
        x = 0, y = height.size()-1;
        while(x<y){
            int area=min(height[y],height[x])*(y-x);
            maxarea=max(maxarea, area);
            if(height[x]<height[y])
                x++;
            else y--;
        }
        return maxarea;
    }
};
