class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int i = 1;
        for(int val : temp) {
            if(mp.find(val) == mp.end()) {
                mp[val] = i;
                i++;
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};