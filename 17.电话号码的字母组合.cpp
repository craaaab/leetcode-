class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneTable{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        int n = digits.length();
        if(n == 0) return ans;
        string combination;
        dfs(ans, phoneTable, combination, 0, digits);
        return ans;
    }

    void dfs(vector<string>& ans, unordered_map<char, string>& phoneTable, string& combination, int index, string& digits) {
        if(index == digits.length()) {
            ans.push_back(combination);
            return;
        }

        char digit = digits[index];
        string chs = phoneTable[digit];
        for(char ch : chs) {
            combination.push_back(ch);
            dfs(ans, phoneTable, combination, index+1, digits);
            combination.pop_back();
        }
    }
};
