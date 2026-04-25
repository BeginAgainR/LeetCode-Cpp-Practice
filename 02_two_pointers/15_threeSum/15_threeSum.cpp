#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results = {};

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j < k && j != k){
                if(nums[j] + nums[k] == target){
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
                else if(nums[j] + nums[k] > target){
                    k--;
                }
                else if(nums[j] + nums[k] < target){
                    j++;
                }
            }
        }

        return results;
    }
};