class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int track = 0;
        for ( int num: nums){
            if ( num != 0 ){
                track++;
            } else{
                result = max(track, result);
                track = 0;
         
            }
        }
        return max(track, result);
    }
};