// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if (mp.count(need)){
                return {mp[need], i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};