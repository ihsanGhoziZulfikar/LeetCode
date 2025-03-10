class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int total=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==k){
                total++;
                i++;
                j--;
            }else if(sum>k){
                j--;
            }else{
                i++;
            }
        }
        return total;
    }
};