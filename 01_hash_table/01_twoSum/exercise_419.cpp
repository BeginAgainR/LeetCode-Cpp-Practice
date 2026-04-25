#include <vector>
#include <unordered_map>

using namespace::vector;
using namespace::unordered_map;

class Solution{
public:
    vector<int> twoSun(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int another = target - num;
            if(mp.count(another)){
                return {mp[another], i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};