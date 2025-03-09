class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result=0;
        double total=0;
        for(int i=0;i<k;i++){
            total+=nums[i];
        }
        result=total;
        for(int i=k;i<nums.size();i++){
            total-=nums[i-k];
            total+=nums[i];
            result=max(result,total);
        }
        return result/k;
    }
};