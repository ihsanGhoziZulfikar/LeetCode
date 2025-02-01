class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // [-2,-2,-2,3,3];
        // [-1,-1,1];
        int total=0;
        int bottom=1001;
        int bottom_i=0;
        for (int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<bottom){
                bottom=total;
                bottom_i=i+1;
            }
        }
        if(total<0)return -1;
        if(bottom_i==gas.size())bottom_i=0;
        return bottom_i;
    }
};