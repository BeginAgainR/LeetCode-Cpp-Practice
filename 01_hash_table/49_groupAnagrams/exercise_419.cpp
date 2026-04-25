#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace::vector;
using namespace::string;
using namespace::unordered_map;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> mp;
        for(auto& str: strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& [key, value] : mp){
            result.push_back(value);
        }
        rerurn result;
    }
};