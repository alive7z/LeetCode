class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int leftPoll = 0, rightPoll = height.size() - 1;
        while(leftPoll < rightPoll) {
            int hgt = min(height[leftPoll], height[rightPoll]);
            int wdh = rightPoll - leftPoll;
            int currWater = hgt * wdh;
            maxWater = max(maxWater, currWater);
            height[leftPoll] < height[rightPoll] ? leftPoll++ : rightPoll--;
        }
        return maxWater;
    }
};