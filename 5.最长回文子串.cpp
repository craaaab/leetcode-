class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        string ans(s, 0, 1);
        for(int i=0; i < n; ++i)
            for(int j=0; j < n; ++j) dp[i][j]=false;
        
        bool flag = false;
        for(int i=0; i < n-1; ++i){
            dp[i][i] = true;
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(!flag){
                    ans.assign(s,i,2);
                    flag = true;
                }
            }
        }
        dp[n-1][n-1] = true;

        for(int i = 3; i <= n; ++i){
            flag = false;
            for(int j = 0; j+i-1<n; ++j){
                if(dp[j+1][j+i-2] && s[j] == s[j+i-1]){
                    if(!flag){
                        ans.assign(s,j,i);
                        flag = true;
                    }
                    dp[j][j+i-1] = true;
                }
            }
        }
        return ans;
    }
};
