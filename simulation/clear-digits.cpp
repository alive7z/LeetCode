class Solution {
public:
    string clearDigits(string s) {
        string str = "";
        vector<char> store;
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                if(!store.empty()) store.pop_back();
            } else store.push_back(c);
        }
        for(char c : store) {
            str += c;
        }
        return str;
    }
};