class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
        while(left<right && top<bottom){
            cout << left << " " << right << endl;
            for(int i=0;i<right-left;i++){
                int temp = matrix[top][left+i];
                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = temp;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
            // for(int i=0;i<matrix.size()-1;i++){
            //     int temp = matrix[top+0][left+i];
            //     matrix[top+0][left+i] = matrix[bottom-i][left+0];         // left right   (top)
            //     matrix[bottom-i][left+0] = matrix[bottom-0][right-i];     //bottom up     (left)
            //     matrix[bottom-0][right-i] = matrix[top+i][right-0];     //right left    (bottom)
            //     matrix[top+i][right-0] = temp;                          //top bottom    (right)
            // }
    }
};

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
//             for(int i=0;i<matrix.size()-1;i++){
//                 int temp = matrix[top+0][left+i];
//                 matrix[top+0][left+i] = matrix[bottom-i][left+0];         // left right   (top)
//                 matrix[bottom-i][left+0] = matrix[bottom-0][right-i];     //bottom up     (left)
//                 matrix[bottom-0][right-i] = matrix[top+i][right-0];     //right left    (bottom)
//                 matrix[top+i][right-0] = temp;                          //top bottom    (right)
//             }
//     }
// };
