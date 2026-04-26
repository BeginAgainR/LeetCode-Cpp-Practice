#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0 , right = 0;

        int maxLength = 0;
        int curLength = 0;

        while(right < s.size())
        {
            if (st.count(s[right]) == 1)
            {
                while(left < right && st.count(s[right]))
                {
                    st.erase(s[left]);
                    left++;
                    curLength--;
                }
            }
            if (st.count(s[right]) != 1)
            {
                st.insert(s[right]);
                curLength++;
                if(curLength > maxLength)
                {
                    maxLength = curLength;
                }
                right++;
            }
        }
        return maxLength;
    }
};