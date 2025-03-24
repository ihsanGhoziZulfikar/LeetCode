class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> v_row, v_col(grid.size());
        for(int i=0;i<grid.size();i++){
            // v_row.push_back(grid[i]);

            for(int j=0;j<grid[i].size();j++){
                v_col[j].push_back(grid[i][j]);
            }
           
        }

        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<v_col.size();j++){
                if(grid[i] == v_col[j]){
                    count++;        
                    // for(int j=0;j<v_col[j].size();j++){
                    //     cout << v_col[i][j] << " ";
                    // }
                }
            }
            
        }

        // for(int i=0;i<v_row.size();i++){
        //     for(int j=0;j<v_row[i].size();j++){
        //         cout << v_row[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=0;i<v_col.size();i++){
        //     for(int j=0;j<v_col[i].size();j++){
        //         cout << v_col[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return count;
    }
};