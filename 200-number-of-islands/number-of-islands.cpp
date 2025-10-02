class Solution {
public:
    map<pair<int,int>,int> visited;
    vector<vector<char>> grid;
    void dfs(int x,int y) {
        if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y]=='1' && !visited[{x,y}]){
            visited[{x,y}] = 1;
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y-1);
            dfs(x,y+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if( grid[i][j] == '0' || visited[{i,j}] ){
                    continue;
                }else{
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};