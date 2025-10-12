class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size());
        v[v.size()-1] = cost[cost.size()-1];;
        v[v.size()-2] = cost[cost.size()-2];
        for(int i=v.size()-3;i>=0;i--){
            v[i] = cost[i] + min(v[i+1], v[i+2]);
        }
        return min(v[0],v[1]);
    }
};