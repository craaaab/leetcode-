class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int pop = x % 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > INT_MAX % 10)) return 0;
            else if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < INT_MIN % 10)) return 0;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
};
