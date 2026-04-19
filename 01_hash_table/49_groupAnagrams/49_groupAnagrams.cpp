// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;

class Solution{
public:
    vector<vector<string>>  groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& [key, group] :mp){
            result.push_back(group);
        }

        return result;
    }
};