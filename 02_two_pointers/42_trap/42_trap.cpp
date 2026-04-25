#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);

        int curLeftMax = height[0], curRightMax = height[height.size() - 1];

        for (int i = 0; i < height.size(); i++){
            if (curLeftMax >= height[i])
            {
                leftMax[i] = curLeftMax;
            }
            else
            {
                curLeftMax = height[i];
                leftMax[i] = curLeftMax;
            }
        }
        for (int i = height.size() - 1; i >= 0; i--){
            if (curRightMax >= height[i])
            {
                rightMax[i] = curRightMax;
            }
            else
            {
                curRightMax = height[i];
                rightMax[i] = curRightMax;
            }
        }
        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            result += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        return result;
    }
};