// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto &num : nums){
            st.insert(num);
        }

        int Length = 0;
        for (auto &num: nums){
            if(st.count(num - 1) != 1){

            }
            else{
                continue;
            }
        }
    }
};