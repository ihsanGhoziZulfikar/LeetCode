class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int x = obstacleGrid[0].size();
        int y = obstacleGrid.size();
        vector<vector<int>> v(y, vector<int>(x));
        int flag=false;
        for(int i=0;i<x;i++){
            if(obstacleGrid[0][i]==1)
                flag=true;
            if(!flag)
                v[0][i]=1;
            else
                v[0][i]=0;
        }
        flag=false;
        
        for(int i=0;i<y;i++){
            if(obstacleGrid[i][0]==1)
                flag=true;
            if(!flag)
                v[i][0]=1;
            else
                v[i][0]=0;
        }

        for(int i=1;i<y;i++){
            for(int j=1;j<x;j++){
                if(obstacleGrid[i][j]==1)
                    v[i][j] = 0;
                else
                    v[i][j] = v[i-1][j]+v[i][j-1];
            }
        }
        return v[y-1][x-1];
    }
};