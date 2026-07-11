class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        string ans = "";
        sort(strs.begin(), strs.end());
        for(int idx = 1; idx < strs.size(); idx++) {
            string first = strs[idx-1];
            string second = strs[idx];
            int i = 0;
            string temp;
            while(i < first.size() && i < second.size()) {
                if(first[i] == second[i]) {
                    temp += first[i];
                } else break;
                i++;
            }
            if(ans.size() == 0) {
                ans = temp; continue;
            }
            if(temp.size() > 0) {
                if(ans.size() > temp.size()) ans = temp;
            } else return "";
        }
        return ans;
    }
};