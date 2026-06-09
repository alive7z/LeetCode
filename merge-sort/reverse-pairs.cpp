class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;
        while(i <= mid && j <= end) {
            if(nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= end) {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i = 0; i < temp.size(); i++) {
            nums[st++] = temp[i];
        }
    }

    int count(vector<int>& nums, int st, int mid, int end) {
        int cnt = 0;
        int j = mid + 1;
        for(int i = st; i <= mid; i++) {
            while(j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        int cnt = 0;
        if(st < end) {
            int mid = st + (end - st) / 2;
            cnt += mergeSort(nums, st, mid);
            cnt += mergeSort(nums, mid + 1, end);
            cnt += count(nums, st, mid, end);
            merge(nums, st, mid, end);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};