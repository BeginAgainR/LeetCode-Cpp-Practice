#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fir = 0, sec = 0;
        while(sec < nums.size()){
            if(sec < nums.size() && nums[sec] != 0){
                nums[fir] = nums[sec];
                fir++, sec++;
            }
            else{
                sec++;
            }
        }
        while(fir < nums.size()){
            nums[fir] = 0;
            fir++;
        }
    }
};