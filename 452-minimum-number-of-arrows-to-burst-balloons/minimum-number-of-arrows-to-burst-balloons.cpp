class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto &left, auto &right){
            return left[1] < right[1];
        });

        int result = 1;
        int min_i = points[0][1];

        int i=0;
        while(i<points.size()){
            while(i<points.size() && min_i >= points[i][0]){
                min_i = max(min_i, points[i][0]);
                i++;
            }
            if(i<points.size()){
                min_i = points[i][1];
                result++;
            }
            i++;
        }
        return result;
    }
};

// [1,6] [2,8] [7,12] [10,16]
// []
        // for(int i=0;i<points.size()-1;i++){
        //     if(points[i][1] >= points[i+1][0]){
        //         min_i = max(points[i][1], points[i+1][0]);
        //         i++;
        //         while(i<points.size() && min_i <= points[i][0]){
        //             min_i = max(min_i, points[i][0]);
        //             i++;
        //         }
        //     }
        //     result++;
        // }