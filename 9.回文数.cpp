class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long tmp = 0, rem = 0, y = x;
        while(x != 0){
            rem = x % 10;
            tmp = tmp * 10 + rem;
            x /= 10;
        }
        return tmp == y;
    }
};
