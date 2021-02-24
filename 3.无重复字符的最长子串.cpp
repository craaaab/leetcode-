class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans=1;
        int lh=0, rh=0;
        while(rh+1 < s.size()){
            rh += 1;
            for(int j = lh; j < rh; ++j){
                if(s[j] == s[rh]) lh = j+1;
            }
            ans = rh - lh + 1 > ans ? rh - lh + 1 : ans;
        }
        return ans;
    }
};
