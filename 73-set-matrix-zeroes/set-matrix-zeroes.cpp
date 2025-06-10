class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> si;
        set<int> sj;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    si.insert(i);
                    sj.insert(j);
                }
            }
        }
        
        for(auto it=si.begin();it!=si.end();++it){
            for(int j=0;j<matrix[0].size();j++){
                matrix[*it][j] = 0;
            }
        }
        for(auto it=sj.begin();it!=sj.end();++it){
            for(int j=0;j<matrix.size();j++){
                matrix[j][*it] = 0;
            }
        }
    }
};