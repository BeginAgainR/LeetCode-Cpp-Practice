#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rownums = matrix.size();
        int colnums = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < rownums; i++)
        {
            for(int j = 0; j < colnums; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(auto c : cols){
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][c] = 0;  // 将列置为 0 了
            }
        }

        for(auto r : rows)
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                if(i == r)
                {
                    for(int j = 0; j < rownums; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
    }
};