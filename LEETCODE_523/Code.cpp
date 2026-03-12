#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> remainder_map;
        remainder_map[0] = -1;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            if (k != 0) current_sum %= k;
            if (remainder_map.find(current_sum) != remainder_map.end()) {
                if (i - remainder_map[current_sum] > 1) return true;
            } else {
                remainder_map[current_sum] = i;
            }
        }
        return false;
    }
};
