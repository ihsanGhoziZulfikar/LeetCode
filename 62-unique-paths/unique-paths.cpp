class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n,1));

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                v[i][j] = v[i+1][j] + v[i][j+1];
                // cout << v[i][j] << " ";
            }
            // cout << endl;
        }

        return v[0][0];
    }
};