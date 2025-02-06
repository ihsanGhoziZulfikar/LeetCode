class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=1;
        int up=2;
        int down=2;
        int prev_incline=0;
        int prev_state=0;
        int prev=ratings[0];
        for(int i=1;i<ratings.size();i++){
            if(prev==ratings[i]){
                result++;
                up=2;
                down=2;
                prev_incline=0;
                prev_state=0;
            }else if(prev<ratings[i]){
                result+=up;
                down=1;
                up++;
                if(prev_state!=1){
                    prev_incline=1;
                }else{
                    prev_incline++;
                }
                prev_state=1;
            }else{
                result+=down;
                up=2;
                if(down==prev_incline)down+=2;
                else down++;
                prev_state=2;
            }
            prev=ratings[i];
        }
        return result;
    }
};

// 1 2 3 2 1 0
// 1 2 4 3 2 1

// 1 2 3 3 2 1
//