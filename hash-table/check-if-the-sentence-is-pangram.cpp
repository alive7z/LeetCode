class Solution {
public:
    bool checkIfPangram(string sentence) {
        int len = sentence.length();
        if(len<26)
            return false;
        int character[26];
        for(int i=0; i<len; i++){
            character[ sentence[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(character[i] == 0)
                return false;
        }
        return true;
    }
};