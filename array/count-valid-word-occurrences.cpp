class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        vector<int> ans;
        
        string joint = "";
        for(string word : chunks) {
            joint += word;
        }
        
        unordered_map<string, int> mp;
        
        string word = "";
        int n = joint.length();
        for(int i = 0; i<n; i++) {
            char val = joint[i];
            if(val >= 'a' && val <= 'z') {
                word += val;
            } else if(i > 0 && i < n-1 && (joint[i-1] >= 'a' && joint[i-1] <= 'z') && (joint[i+1] >= 'a' && joint[i+1] <= 'z') && val == '-' ) {
                word += val;
            } else {
                if(!word.empty()) {
                    mp[word]++;
                    word = "";
                }
            }
        }
        
        if(!word.empty()) {
            mp[word]++;
        }
        
        for(string val : queries) {
            ans.push_back(mp[val]);
        }
        
        return ans;
    }
};