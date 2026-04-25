#include <vector>

using namespace::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fir = 0, sec = 0;
        while(sec < nums.size()){
            if(nums[fir] != 0){
                fir++;
                if(sec < fir){
                    sec = fir;
                }
            }
            if(nums[fir] == 0){
                while(sec < num.size() && nums[sec] != 0){
                    sec++;
                }  // 找到了
            }
            nums[fir] = nums[sec];
            fir++, sec++;
        }
        while(fir < nums.size()){
            nums[fir] = 0;
        }
    }     
};