// 双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int res = 0;
        for(int i = 0, j = height.size() - 1; i < j;) {
            int cur = min(height[i], height[j]);
            res = max(res, cur*(j-i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};
