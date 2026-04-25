#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fir = 0, sec = 0;
        while(sec < nums.size()){
            while(fir < nums.size() && nums[fir] != 0){
                fir++;  // 寻找插入位置
            }  // 找到了
            sec = fir;
            while(sec < nums.size() && nums[sec] == 0){
                sec++;
            }  // 找到了
            if(sec < nums.size()){
                nums[fir] = nums[sec];
                fir++, sec++;
            }
            

        }
        while(fir < nums.size()){
            nums[fir] = 0;
        }
        
    }
};