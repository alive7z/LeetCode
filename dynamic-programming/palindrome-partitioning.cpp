class Solution {
public:
    
    bool isPalindrome(string part) {
        string rev = part;
        reverse(rev.begin(), rev.end());
        return rev == part;
    }

    void partition(string s, vector<vector<string>>& ans, vector<string>& partitions) {
        if(s.size() == 0) {
            ans.push_back({partitions});
            return;
        }
        for(int i = 0; i<s.size(); i++) {
            string part = s.substr(0, i+1);
            if(isPalindrome(part)) {
                partitions.push_back(part);
                partition(s.substr(i+1), ans, partitions);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        partition(s, ans, partitions);
        return ans;
    }
};