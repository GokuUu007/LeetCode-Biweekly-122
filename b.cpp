// Problem Name - 3011. Find if Array Can Be Sorted

class Solution {
public:
    bool canSortArray(vector<int>& nums) { 
        auto bits = [&] (int x) {
            int cnt = 0;
            for (int i = 0; i < 10; ++i) {
                if ((x >> i) & 1) {
                    cnt += 1;
                }
            }
            return cnt;
        };
        
        int n = nums.size();
        vector<int> can_swap(n);
        for (int i = 0; i + 1 < n; ++i) {
            can_swap[i] = bits(nums[i]) == bits(nums[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < n; ++j) {
                if (can_swap[j]) {
                    if (nums[j] > nums[j + 1]) {
                        swap(nums[j], nums[j + 1]);
                    }
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};
