#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> up_s;
        unordered_map<char, int> up_p;
        vector<int> result;

        int length = p.size();
        int left = 0;
        int right = length - 1;

        for(int i = 0; i < p.size(); i++){
            up_p[p[i]]++;
        }
        for(int i = 0; i < p.size(); i++){
            up_s[s[i]]++;
        }
        while(right < s.size())
        {
            if (up_s == up_p)
            {
                result.push_back(left);
                up_s[s[left]]--;
                left++;
                right++;
                up_s[s[right]]++;
            }
            else if(right < s.size())
            {
                up_s[s[left]]--;
                left++;
                if(right < length -1)
                {
                    right++;
                    up_s[s[right]]++;
                }
                else
                {
                    break;
                }
                
            }
        }
        return result;
    }
};