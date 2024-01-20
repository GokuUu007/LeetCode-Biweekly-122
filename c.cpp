// Problem Name - 3012. Minimize Length of Array Using Operations

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[0] == nums[i]) cnt += 1;
            else {
                if (nums[i] % nums[0]) return 1;
            }
        }
        return (cnt + 1) / 2;
    }
};
